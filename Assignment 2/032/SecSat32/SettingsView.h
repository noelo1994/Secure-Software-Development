#pragma once

#include <fstream>
#include "SettingsViewUserRequestedAction.h"
#include "ISettingsView.h"

class SecureString;
class User;

/// A Windows console implementation of ISettingsView.
class SettingsView : public ISettingsView
{
public:
   explicit SettingsView(const User& user);
   SettingsViewUserRequestedAction GetUserRequestedAction() const override { return m_userRequestedAction; }
   std::pair<LoggerType, LogFormatType> GetRequestedLoggerConfiguration() const override { return m_requestedLoggerConfiguration; }
   std::pair<std::string, Role> GetRequestedUserRoleChange() const override { return m_requestedUserRoleChange; }
   void Close() override;
   bool Process() override;
   void DisplayCurrentUsersAndAccessLevels(const SecureString& currentUsersAndAccessLevels) override;
   void DisplayPermissionDenied() const override;
    
private:
   void RedirectIO();
   void ResetIO();
   bool GetRequestedLoggerConfiguration();
   bool GetRequestedUserAccessChange();
   static void WaitForCharacter(const int8_t toWaitFor);
   static void DisplayActionList();

   std::pair<LoggerType, LogFormatType> m_requestedLoggerConfiguration;
   std::pair<std::string, Role> m_requestedUserRoleChange;
   bool m_isOpen = false;
   SettingsViewUserRequestedAction m_userRequestedAction;
   std::streambuf *m_cinBuffer = nullptr;
   std::streambuf *m_coutBuffer = nullptr;
   std::fstream m_consoleInput;
   std::fstream m_consoleOutput;
};
