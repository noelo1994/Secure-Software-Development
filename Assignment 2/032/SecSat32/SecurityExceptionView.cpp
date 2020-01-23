#include "SecurityExceptionView.h"
#include "resource.h"

SecurityExceptionView::SecurityExceptionView() : SecurityExceptionView(nullptr)
{   
}

SecurityExceptionView::SecurityExceptionView(const HWND parentHandle) :
   DialogView(CreateDialog(GetModuleHandle(nullptr), MAKEINTRESOURCE(dialogSecurityException),
      parentHandle, ProcessDialogMessages))
{
   ShowWindow(m_dialogHandle, SW_SHOW);
}

BOOL WINAPI SecurityExceptionView::ProcessDialogMessages(const HWND dialogHandle, const UINT message, const WPARAM, const LPARAM)
{
   switch (message)
   {
      case WM_COMMAND: // The 'OK' button will do the same as the close button
      case WM_CLOSE:
      {
         DestroyWindow(dialogHandle);
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

 