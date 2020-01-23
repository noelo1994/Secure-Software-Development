#include "LoginView.h"
#include "resource.h"
#include <chrono>
#include <thread>
#include "SettingsView.h"

LoginView::LoginView() : 
   DialogView(CreateDialogParam(GetModuleHandle(nullptr), MAKEINTRESOURCE(dialogLogin),
      nullptr, DlgProc, reinterpret_cast<LPARAM>(this)))
{
   ShowWindow(m_dialogHandle, SW_SHOW);
}

bool LoginView::Process() const
{
   // GetMessage returns nonzero if it retrieves a message other than WM_QUIT,
   // zero if the message is WM_QUIT, and -1 if there is an error.
   MSG message;
   bool messageIsRetrieved = GetMessage(&message, nullptr, 0, 0) > 0;

   if ((messageIsRetrieved) && (IsDialogMessage(m_dialogHandle, &message)))
   {
      // Dispatching these messages results in key presses being repeated in edit controls
      if ((message.message != WM_KEYDOWN) && (message.message != WM_CHAR))
      {
         TranslateMessage(&message);
         DispatchMessage(&message);
      }
   }

   return messageIsRetrieved;
}

SecureString LoginView::GetUserIDInput()
{
   SecureString userInput = m_userIDInput;
   m_userIDInput.Clear();                 // Overwrite the class member for security purposes
   return userInput;
}

SecureString LoginView::GetUserPasswordInput()
{
   SecureString userInput = m_userPasswordInput;
   m_userPasswordInput.Clear();                 // Overwrite the class member for security purposes
   return userInput;
}

void LoginView::ShowInvalidLoginWarning()
{
   ShowWindow(GetDlgItem(m_dialogHandle, textInvalidLogin), SW_SHOW);
}

BOOL WINAPI LoginView::DlgProc(HWND dialogHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
   // [D16] Initialising pointer to nullptr
   LoginView* instance = nullptr;

   if (message == WM_INITDIALOG)
   {
      // Get the instance pointer given at creation of the dialog, and store it in DWLP_USER
      instance = reinterpret_cast<LoginView*>(lParam);
      SetWindowLongPtr(dialogHandle, DWLP_USER, reinterpret_cast<LONG_PTR>(instance));
   }
   else
   {
      // Retrieve the instance pointer stored when the WM_INITDIALOG message was received
      instance = reinterpret_cast<LoginView*>(GetWindowLongPtr(dialogHandle, DWLP_USER));
   }

   if (instance)
   {
      // Call the instance specific message handler
      return instance->ProcessDialogMessages(message, wParam);
   }

   // The instance pointer has not yet been assigned
   return FALSE;
}

BOOL LoginView::ProcessDialogMessages(const UINT message, const WPARAM wParam)
{
   switch (message)
   {
      case WM_COMMAND:
      {
         if (LOWORD(wParam) == buttonSubmit)
         {        
            // GetWindowTextLength does not account for the null terminator, so 1 is added to both buffer sizes
            // Get user ID text
            const size_t userIDBufferSize = GetWindowTextLength(GetDlgItem(m_dialogHandle, editBoxUserID)) + 1;
            const auto userID = std::make_unique<char[]>(userIDBufferSize);
            GetDlgItemText(m_dialogHandle, editBoxUserID, userID.get(), userIDBufferSize);
            m_userIDInput.SetValue(userIDBufferSize, userID.get());

            // [D15] CERT MEM03 - CPP (Clear sensitive information stored in returned reusable resources)
            SecureZeroMemory(userID.get(), userIDBufferSize); 

            // Get password text
            // [D13] Getting length of text to prevent buffer overflow
            // [D14] Use of smart pointer to handle memory management
            const size_t passwordBufferSize = GetWindowTextLength(GetDlgItem(m_dialogHandle, editBoxPassword)) + 1;
            const auto password = std::make_unique<char[]>(passwordBufferSize); 
            GetDlgItemText(m_dialogHandle, editBoxPassword, password.get(), passwordBufferSize);  
            m_userPasswordInput.SetValue(passwordBufferSize, password.get());
            SecureZeroMemory(password.get(), userIDBufferSize);

            NotifyObservers();
         }

         return TRUE;
      }

      case WM_CLOSE:
      {
         DestroyWindow(m_dialogHandle);
         return TRUE;
      }

      case WM_DESTROY:
      {
         PostQuitMessage(0);
         return TRUE;
      }

      default:
      {
         return FALSE;
      }
   }
}
