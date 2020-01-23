#pragma once

#include "DialogView.h"

/// A Win32 dialog indicating that something has gone wrong and the application is about to close.
class SecurityExceptionView : public DialogView
{
public:
   SecurityExceptionView();
   explicit SecurityExceptionView(const HWND parentHandle);

private:
   static BOOL WINAPI ProcessDialogMessages(const HWND dialogHandle, const UINT message, const WPARAM wParam, const LPARAM lParam);
};
