#pragma once

#include "Subject.h"

class SecureString;
enum class LoggerType;
enum class LogFormatType;
enum class Role;

/// Allows abstraction of a settings view.
class ISettingsView : public Subject
{
public:
   virtual ~ISettingsView()
   {
   }

   virtual bool Process() = 0;;
   virtual SettingsViewUserRequestedAction GetUserRequestedAction() const = 0;
   virtual void Close() = 0;
   virtual void DisplayCurrentUsersAndAccessLevels(const SecureString& currentUsersAndAccessLevels) = 0;
   virtual std::pair<LoggerType, LogFormatType> GetRequestedLoggerConfiguration() const = 0; 
   virtual std::pair<std::string, Role> GetRequestedUserRoleChange() const = 0;
   virtual void DisplayPermissionDenied() const = 0;
};