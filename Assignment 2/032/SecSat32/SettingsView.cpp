#include <Windows.h>
#include <iostream>
#include "SettingsView.h"
#include "Console.h"
#include "User.h"
#include "PermissionChecker.h"
#include "AccessLevel.h"
#include "ResourceType.h"
#include "LogFormatType.h"
#include "LoggerType.h"

SettingsView::SettingsView(const User& user) :
m_userRequestedAction(SettingsViewUserRequestedAction::None)
{
   PermissionChecker permissionChecker;

   if ((!permissionChecker.CheckPermission(ResourceType::Settings, user.GetRole(), AccessLevel::Readonly) &&
       (!permissionChecker.CheckPermission(ResourceType::Settings, user.GetRole(), AccessLevel::Full))))
   {
      throw SecurityException("Unauthorised access to system settings.");
   }

   AllocConsole();
   RedirectIO();
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
   m_isOpen = true;
}

void SettingsView::Close()
{
   ResetIO();
   FreeConsole();
}

void SettingsView::RedirectIO()
{
   m_cinBuffer = cin.rdbuf();
   m_coutBuffer = cout.rdbuf();
   m_consoleInput.open("CONIN$", ios::in);
   m_consoleOutput.open("CONOUT$", ios::out);
   cin.rdbuf(m_consoleInput.rdbuf());
   cout.rdbuf(m_consoleOutput.rdbuf());
}

void SettingsView::ResetIO()
{
   m_consoleInput.close();
   m_consoleOutput.close();
   cin.rdbuf(m_cinBuffer);
   cout.rdbuf(m_coutBuffer);
   m_cinBuffer = nullptr;
   m_coutBuffer = nullptr;
}

void SettingsView::WaitForCharacter(const int8_t toWaitFor)
{
   char input;

   do
   {
      cin.width(2);
      cin >> input;
   } while (input != toWaitFor);
}

bool SettingsView::Process()
{
   if (m_isOpen)
   {
      DisplayActionList();
      string input;
      cin.width(2);
      cin >> input;

      if (!input.empty())
      {
         switch (input[0])
         {
            case '1':
            {
               m_userRequestedAction = SettingsViewUserRequestedAction::ViewUsers;
               NotifyObservers();
               break;
            }

            case '2':
            {
               if (GetRequestedUserAccessChange())
               {
                  m_userRequestedAction = SettingsViewUserRequestedAction::ChangeUserRole;
                  NotifyObservers();
               }

               break;
            }

            case '3':
            {
               if (GetRequestedLoggerConfiguration())
               {
                  m_userRequestedAction = SettingsViewUserRequestedAction::ChangeLoggerConfiguration;
                  NotifyObservers();
               }

               break;
            }

            case '4':
            {
               Close();
               m_isOpen = false;
               break;
            }

            default:
            {
               break;
            }
         }
      }
   }

      return m_isOpen;
}

bool SettingsView::GetRequestedUserAccessChange()
{
   cout << "---------------- Select New Logger Settings ----------------" << "\n\n";
   cout << "Enter the name of the user, or enter 0 to cancel." << "\n\n";

   string userName;

   // [D17] using cin for input into a string, with set width
   // Width is set to omething sensible for the max length of a user ID
   cin.width(30); 

   cin >> userName;

   if (userName == "0")
   {
      return false;
   }

   cout << "Select the new access level by entering a number (changes to your own account will be effective after this session):" << "\n\n";
   cout << "0. Unauthorised " << "\n";
   cout << "1. Analyst" << "\n";
   cout << "2. Operator" << "\n";
   cout << "3. Director" << "\n";
   cout << "\n" << "Or enter any other character to cancel." << "\n";

   string role;
   cin.width(2);
   cin >> role;

   if (!role.empty())
   {
      switch (role[0])
      {
         case '0': m_requestedUserRoleChange = pair<string, Role>(userName, Role::Unauthorised); return true;
         case '1': m_requestedUserRoleChange = pair<string, Role>(userName, Role::Analyst); return true;
         case '2': m_requestedUserRoleChange = pair<string, Role>(userName, Role::Operator); return true;
         case '3': m_requestedUserRoleChange = pair<string, Role>(userName, Role::Director); return true;
         default: break;
      }
   }

   return false;
}

bool SettingsView::GetRequestedLoggerConfiguration()
{
   cout << "---------------- Select New Logger Settings ----------------" << "\n\n";
   cout << "Please select a new logging configuration by entering a number:" << "\n\n";
   cout << "1. Plain text" << "\n";
   cout << "2. Encrypted text" << "\n";
   cout << "3. Plain binary" << "\n";
   cout << "4. Encrypted binary" << "\n";
   cout << "\n" << "Or enter any other character to cancel." << "\n\n";

   string configuration;
   cin.width(2);
   cin >> configuration;

   if (!configuration.empty())
   {
      switch (configuration[0])
      {
         case '1': m_requestedLoggerConfiguration = pair<LoggerType, LogFormatType>(LoggerType::Text, LogFormatType::Plain); return true;
         case '2': m_requestedLoggerConfiguration = pair<LoggerType, LogFormatType>(LoggerType::Text, LogFormatType::Encrypted); return true;
         case '3': m_requestedLoggerConfiguration = pair<LoggerType, LogFormatType>(LoggerType::Binary, LogFormatType::Plain); return true;
         case '4': m_requestedLoggerConfiguration = pair<LoggerType, LogFormatType>(LoggerType::Binary, LogFormatType::Encrypted); return true;
         default: break;
      }
   }

   return false;
}

void SettingsView::DisplayCurrentUsersAndAccessLevels(const SecureString& currentUsersAndAccessLevels)
{
   cout << "---------------- Current Users and Roles ----------------" << "\n\n";
   cout << "Key: 0: Unauthorised 1: Analyst  2: Operator  3: Director" << "\n\n";
   cout << currentUsersAndAccessLevels.GetValue();
   cout << "\n" << "Enter 0 to return to the action menu." << '\n';
   WaitForCharacter('0');
}

void SettingsView::DisplayPermissionDenied() const
{
   cout << "\n" << "----------------PERMISSION DENIED----------------";
   cout << "\n" << "----------------PERMISSION DENIED----------------";
   cout << "\n" << "----------------PERMISSION DENIED----------------" << "\n\n";
}

void SettingsView::DisplayActionList()
{
   cout << "---------------- Secure Satellite 32 Settings Manager ----------------" << "\n\n";
   cout << "Please select an operation by entering a number:" << "\n\n";
   cout << "1. View users and access levels" << "\n";
   cout << "2. Change the access level of a user*" << "\n";
   cout << "3. Change logging options*" << "\n";
   cout << "4. Return to Secure Satellite 32" << "\n";
   cout << "\n";
   cout << "* Directors only" << "\n\n";
}
