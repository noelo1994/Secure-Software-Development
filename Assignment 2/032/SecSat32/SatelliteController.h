#pragma once

#include <memory>
#include "IObserver.h"
#include "PermissionChecker.h"
#include "SatelliteModel.h"
#include "AuthenticationRepository.h"
#include "ISatelliteView.h"
#include "User.h"

class User;

/// Mediates between the SatelliteView and SatelliteModel.
class SatelliteController : public IObserver 
{
public:
   explicit SatelliteController(std::unique_ptr<ISatelliteView> view, const User user);

   /// Checks the view to see which action the user has requested, and handles the request.
   void Update(const Subject* const subject) override;

   /// Instructs the view to do whatever the view does.
   void ProcessView() const;

private:
   void HandleToggleATCSRequest() const;
   void HandleSelfDestructRequest() const;
   void HandleOpenSettingsManagerRequest() const;
   void SetViewTemperatureDisplay() const;

   std::unique_ptr<SatelliteModel> m_model;
   std::unique_ptr<ISatelliteView> m_view;
   const std::unique_ptr<User> m_user;
   std::unique_ptr<AuthenticationRepository> m_authenticationRepository;
   std::unique_ptr<PermissionChecker> m_permissionChecker;
};
