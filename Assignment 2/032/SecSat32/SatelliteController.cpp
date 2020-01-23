#include "SatelliteController.h"
#include "AccessLevel.h"
#include "LoggedSatelliteModelFactory.h"
#include "SettingsView.h"
#include "AuthenticationFactory.h"
#include "SettingsController.h"
#include "SatelliteViewUserRequestedAction.h"
#include "ResourceType.h"

SatelliteController::SatelliteController(std::unique_ptr<ISatelliteView> view, const User user) : m_view(move(view)), m_user(std::make_unique<User>(user))
{
   AuthenticationFactory authenticationFactory;
   m_authenticationRepository = authenticationFactory.CreateAuthenticationRepository();
   m_permissionChecker = authenticationFactory.CreatePermissionChecker();

   LoggedSatelliteModelFactory loggedSatelliteFactory;
   m_model = loggedSatelliteFactory.CreateLoggedSatelliteModel();

   m_model->RegisterObserver(this);
   m_view->RegisterObserver(this);
   m_model->StartReadings();
}

void SatelliteController::Update(const Subject* const subject)
{
   const void* const subjectAddress = subject;

   // After self destruct, threads may take some time to finish
   // The controller ignores information from the model if the model is not in an operational state
   if ((subjectAddress == m_model.get()) && (m_model->GetIsOperational()))
   {
      SetViewTemperatureDisplay();
      m_view->SetSolarRadiationReading(m_model->GetSolarRadiationReading());
      m_view->SetGravityAnomalyReading(m_model->GetGravityAnomalyReading());
   }
   else if (subjectAddress == m_view.get())
   {
      if (m_authenticationRepository->ValidateUserSessionID(*m_user))
      {
         switch (m_view->GetUserRequestedAction())
         {
            case SatelliteViewUserRequestedAction::ToggleActiveThermalControlSystem: HandleToggleATCSRequest(); break;
            case SatelliteViewUserRequestedAction::SelfDestruct: HandleSelfDestructRequest(); break;
            case SatelliteViewUserRequestedAction::OpenSettingsManager: HandleOpenSettingsManagerRequest(); break;
            case SatelliteViewUserRequestedAction::None:
            default: break;
         }
      }
      else
      {
         throw SecurityException("Unvalidated user detected after the login stage.");
      }
   }
}
       
void SatelliteController::ProcessView() const
{
   while (m_view->Process())
   {
   }
}

void SatelliteController::HandleToggleATCSRequest() const
{
   if (m_permissionChecker->CheckPermission(ResourceType::ActiveThermalControlSystem, m_user->GetRole(), AccessLevel::Full))
   {
      m_model->ToggleActiveThermalControl(*m_user);
   }
   else
   {
      m_view->IndicateATCSPermissionDenied();
   }
}

void SatelliteController::HandleSelfDestructRequest() const
{
   if (m_permissionChecker->CheckPermission(ResourceType::SelfDestruct, m_user->GetRole(), AccessLevel::Full))
   {
      m_model->SelfDestruct(*m_user);
      m_view->IndicateLostConnection();
   }
   else
   {
      m_view->IndicateSelfDestructPermissionDenied();
   }
}

void SatelliteController::HandleOpenSettingsManagerRequest() const
{
   if ((m_permissionChecker->CheckPermission(ResourceType::Settings, m_user->GetRole(), AccessLevel::Full)) ||
      (m_permissionChecker->CheckPermission(ResourceType::Settings, m_user->GetRole(), AccessLevel::Readonly)))
   {
      auto settingsView = std::make_unique<SettingsView>(*m_user);
      SettingsController settingsController(move(settingsView), *m_user);
      settingsController.ProcessView();
   }
   else
   {
      m_view->IndicateSettingsPermissionDenied();
   }
}

void SatelliteController::SetViewTemperatureDisplay() const
{
   SecureDouble temperatureReading = m_model->GetTemperature();
   m_view->SetSatelliteTemperatureReading(temperatureReading);

   if (m_model->GetIsOutOfOperatingTemperatureRange())
   {
      m_view->ShowTemperatureWarning();
   }
   else
   {
      m_view->HideTemperatureWarning();
   }
}
