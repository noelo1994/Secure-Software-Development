#include "SettingsController.h"
#include "AuthenticationFactory.h"
#include "AccessLevel.h"
#include "LoggedSatelliteModelFactory.h"
#include "ResourceType.h"
#include "AuthenticationRepository.h"
#include "SettingsView.h"
#include "PermissionChecker.h"

SettingsController::SettingsController(std::unique_ptr<ISettingsView> view, const User& user) : m_view(move(view))
{
   m_user.SetRole(user.GetRole());
   m_user.SetSessionID(user.GetSessionID());

   AuthenticationFactory authenticationFactory;
   m_authenticationRepository = authenticationFactory.CreateAuthenticationRepository();
   m_permissionChecker = authenticationFactory.CreatePermissionChecker();

   m_view->RegisterObserver(this);
}

void SettingsController::ProcessView() const
{
   while (m_view->Process())
   {
   }
}

void SettingsController::Update(const Subject* const)
{
   if (m_authenticationRepository->ValidateUserSessionID(m_user))
   {
      switch (m_view->GetUserRequestedAction())
      {
         case SettingsViewUserRequestedAction::ViewUsers: HandleViewUsersRequest(); break;
         case SettingsViewUserRequestedAction::ChangeLoggerConfiguration: HandleChangeLoggingConfigurationRequest(); break;
         case SettingsViewUserRequestedAction::ChangeUserRole: HandleChangeUserRoleRequest(); break;
         default: throw SecurityException("Settings view user requested action was not recognised.");
      }     
   }
   else
   {
      throw SecurityException("Unvalidated user detected after the login stage.");
   }
}

void SettingsController::HandleViewUsersRequest() const
{
   if ((m_permissionChecker->CheckPermission(ResourceType::Settings, m_user.GetRole(), AccessLevel::Readonly)) ||
      (m_permissionChecker->CheckPermission(ResourceType::Settings, m_user.GetRole(), AccessLevel::Full)))
   {
      m_view->DisplayCurrentUsersAndAccessLevels(m_authenticationRepository->GetListOfUsersAndRoles(m_user));
   }
   else
   {
      m_view->DisplayPermissionDenied();
   }
}

void SettingsController::HandleChangeUserRoleRequest() const
{
   if (m_permissionChecker->CheckPermission(ResourceType::Settings, m_user.GetRole(), AccessLevel::Full))
   {
      std::pair<std::string, Role> requestedUserRoleChange = m_view->GetRequestedUserRoleChange();
      m_authenticationRepository->ChangeUserRole(requestedUserRoleChange.first, requestedUserRoleChange.second, m_user);
   }
   else
   {
      m_view->DisplayPermissionDenied();
   }
}

void SettingsController::HandleChangeLoggingConfigurationRequest() const
{
   if (m_permissionChecker->CheckPermission(ResourceType::Settings, m_user.GetRole(), AccessLevel::Full))
   {
      std::pair<LoggerType, LogFormatType> requestedLoggerConfiguration = m_view->GetRequestedLoggerConfiguration();
      LoggedSatelliteModelFactory::ChangeLoggerType(requestedLoggerConfiguration.first, requestedLoggerConfiguration.second, m_user);
   }
   else
   {
      m_view->DisplayPermissionDenied();
   }
}
