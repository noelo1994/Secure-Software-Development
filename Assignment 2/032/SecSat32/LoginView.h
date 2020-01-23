#pragma once

#include "ILoginView.h"
#include "DialogView.h"
#include "SecureString.h"

/// A Win32 implementation of ILoginView.
class LoginView : public ILoginView, public DialogView
{
public:
   LoginView();
   bool Process() const override;
   SecureString GetUserIDInput() override;
   SecureString GetUserPasswordInput() override;
   void ShowInvalidLoginWarning() override;
   void Close() const override { DialogView::Close(); }

private:
   BOOL ProcessDialogMessages(const UINT message, const WPARAM wParam);
   static BOOL WINAPI DlgProc(HWND dialogHandle, UINT message, WPARAM wParam, LPARAM lParam);

   SecureString m_userIDInput;
   SecureString m_userPasswordInput;
};
