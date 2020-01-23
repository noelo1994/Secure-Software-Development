#include "LoginController.h"
#include "LoginView.h"
#include "AuthenticationRepository.h"
#include "AuthenticationFactory.h"

LoginController::LoginController(std::unique_ptr<ILoginView> view) :
m_authenticationRepository(AuthenticationFactory().CreateAuthenticationRepository()),
m_view(move(view))
{
   m_view->RegisterObserver(this);
}

void LoginController::Update(const Subject* const)
{
   User user = m_authenticationRepository->CreateUser(m_view->GetUserIDInput(), m_view->GetUserPasswordInput());

   if (m_authenticationRepository->ValidateUserSessionID(user))
   {
      m_loginResult = LoginResult(user);
      m_view->Close();
   }
   else
   {
      m_view->ShowInvalidLoginWarning();
   }
}

void LoginController::ProcessView() const
{
   while (m_view->Process())
   {
   }
}

void LoginController::CloseView() const
{
   m_view->Close();
}
