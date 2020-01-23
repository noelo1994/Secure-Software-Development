#pragma once

#include <memory>
#include "IObserver.h"
#include "User.h"

class PermissionChecker;
class ISettingsView;
class AuthenticationRepository;

/// Controls the SettingsView and handles requests from the same.
class SettingsController : IObserver
{
public:
   explicit SettingsController(std::unique_ptr<ISettingsView> view, const User& user);

   /// Instructs the view to do whatever it is that the view does.
   void ProcessView() const;

   /// Checks the view to see which action the user has requested, and attempts to handle the request.
   void Update(const Subject* const) override;

private:
   void HandleViewUsersRequest() const;
   void HandleChangeUserRoleRequest() const;
   void HandleChangeLoggingConfigurationRequest() const;
 
   const std::unique_ptr<ISettingsView> m_view;
   std::unique_ptr<AuthenticationRepository> m_authenticationRepository;
   std::unique_ptr<PermissionChecker> m_permissionChecker;
   User m_user;
};
