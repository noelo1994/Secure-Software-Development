#pragma once

#include <memory>
#include "LoginResult.h"
#include "IObserver.h"

class AuthenticationRepository;
class ILoginView;

/// Controls the login view and makes the result of the login available.
class LoginController : public IObserver
{
public:
   explicit LoginController(std::unique_ptr<ILoginView> view);

   /// Attempts to validate a user based on the information from the view. If the user is validated,
   /// updates the login result.
   void Update(const Subject* const subject) override;

   /// Instructs the view to do whatever it is that the view does.
   void ProcessView() const;

   /// Instructs the view to close.
   void CloseView() const;

   LoginResult GetLoginResult() const { return m_loginResult; }

private:
   std::unique_ptr<AuthenticationRepository> m_authenticationRepository;
   const std::unique_ptr<ILoginView> m_view;
   LoginResult m_loginResult;
};
