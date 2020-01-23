#pragma once

#include "Subject.h"

class SecureString;

/// Allows abstraction of a login view.
class ILoginView : public Subject
{
public:
   virtual ~ILoginView()
   {
   }

   virtual SecureString GetUserIDInput() = 0;
   virtual SecureString GetUserPasswordInput() = 0;
   virtual void ShowInvalidLoginWarning() = 0;
   virtual bool Process() const = 0;
   virtual void Close() const = 0; 
};
