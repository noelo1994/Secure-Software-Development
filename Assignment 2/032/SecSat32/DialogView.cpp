#include "DialogView.h"

DialogView::DialogView(const HWND dialogHandle) : m_dialogHandle(dialogHandle)
{
}

bool DialogView::Process() const
{
   // GetMessage returns nonzero if it retrieves a message other than WM_QUIT,
   // zero if the message is WM_QUIT, and -1 if there is an error.
   MSG message;
   bool messageIsRetrieved = GetMessage(&message, nullptr, 0, 0) > 0; 

   if ((messageIsRetrieved) && (IsDialogMessage(m_dialogHandle, &message)))
   {
      TranslateMessage(&message);
      DispatchMessage(&message);
   }

   return messageIsRetrieved;
}

void DialogView::Close() const
{
   DestroyWindow(m_dialogHandle);
}
