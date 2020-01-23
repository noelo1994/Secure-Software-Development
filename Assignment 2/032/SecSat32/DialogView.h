#pragma once

#include <Windows.h>

/// Base class for Win32 dialog views.
class DialogView 
{
public:
   explicit DialogView(const HWND dialogHandle);

   virtual ~DialogView()
   {
   }

   /// Processes windows messages. Returns true if messages were processed.
   virtual bool Process() const;

   /// Closes the window.
   virtual void Close() const;

   HWND GetHandle() const { return m_dialogHandle; }

protected:
   const HWND m_dialogHandle;
};
