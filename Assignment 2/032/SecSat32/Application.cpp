#include <memory>
#include <Windows.h>
#include "Application.h"
#include "LoginView.h"
#include "LoginController.h"
#include "SatelliteView.h"
#include "SatelliteController.h"
#include "SecurityExceptionController.h"
#include "SecurityExceptionView.h"

bool Application::m_isRunning = false;

int32_t Application::Run() const
{
   int32_t returnCode = EXIT_SUCCESS;

   if (!m_isRunning)
   {
      m_isRunning = true;
      HWND viewHandle = nullptr;

      try // Encases entire application
      {
         // [D3] Use of make_unique in case of an exception between allocating memory and transferring 
         // ownership to a smart pointer.
         auto loginView = std::make_unique<LoginView>(); 

         viewHandle = loginView->GetHandle();
         const LoginController loginController(move(loginView));
         loginController.ProcessView();
         viewHandle = nullptr;
         const LoginResult loginResult = loginController.GetLoginResult();

         if (loginResult.GetIsSuccess())
         {
            auto satelliteView = std::make_unique<SatelliteView>();
            viewHandle = satelliteView->GetHandle();
            const SatelliteController satelliteController(move(satelliteView), loginResult.GetUser());
            satelliteController.ProcessView();
            viewHandle = nullptr;
         }
      }
      catch (const SecurityException&) // On SecurityException, display a message box before ending the application
      {
         // View handle will be the parent window, or nullptr if an exception is thrown during the time where a window does not exist
         const SecurityExceptionController exceptionController(std::make_unique<SecurityExceptionView>(viewHandle));
         exceptionController.ProcessView();
         returnCode = EXIT_FAILURE;
      }
   }

   return returnCode;
}
