#include <sstream>
#include <fstream>
#include "AuthenticationRepository.h"
#include "Cryptography.h"
#include "Random.h"
#include "User.h"
#include "SecureString.h"
#include "UserDetails.h"
#include "PermissionChecker.h"
#include "AccessLevel.h"
#include "ResourceType.h"
#include "SecureInt32.h"

SecureString AuthenticationRepository::m_validSessionID;;

AuthenticationRepository::AuthenticationRepository()
{
   // Initialise the session ID if it is not yet initialised by another instance, 
   if (m_validSessionID.GetLength() == 0)
   {
      GenerateSessionID();
   }
}

User AuthenticationRepository::CreateUser(const SecureString& userID, const SecureString& password) const
{ 
   User user;
   UserDetails userDetails = GetUserDetails(userID);

   if ((userDetails.GetIsValid()) && (userDetails.GetRole() != Role::Unauthorised))
   {
      SecureInt32 pepper(Cryptography::MinPepper);
      
      while ((!ValidateUserSessionID(user)) && (pepper.GetValue() <= Cryptography::MaxPepper))
      {
         // We know that pepper will only hold a value between min and max pepper, it is in a larger type to avoid overflow when iterating.
         // Therefore, in this instance we know it is ok to cast to the smaller type.
         SecureString hashedPassword = Cryptography::HashString(password + userDetails.GetSalt(), static_cast<int8_t>(pepper.GetValue()));

          if (userDetails.GetHashedPassword() == hashedPassword)
         {
            user.SetSessionID(GenerateSessionID());
            user.SetRole(userDetails.GetRole());
         }

         ++pepper;
      }
   }

   return user;
}

bool AuthenticationRepository::ValidateUserSessionID(const User& user) const
{
   return user.GetSessionID() == m_validSessionID;
}

SecureString AuthenticationRepository::GetListOfUsersAndRoles(const User& user)
{
   PermissionChecker permissionChecker;

   if ((!permissionChecker.CheckPermission(ResourceType::Settings, user.GetRole(), AccessLevel::Readonly)) &&
      (!permissionChecker.CheckPermission(ResourceType::Settings, user.GetRole(), AccessLevel::Full)))
   {
      throw SecurityException("Unauthorised access to system settings.");
   }

   SecureString list;
   std::ifstream inputFileStream("UserDatabase.txt");
   SecureString repositoryUserID, role, salt, hashedPassword;

   while (inputFileStream >> repositoryUserID >> role >> salt >> hashedPassword)
   {
      list += repositoryUserID + ' ';
      list += role + '\n';
   }

   return list;
}

/// Reads in the entire user database. If the given user ID is found, then the corresponding role is changed to the
/// given role. The entire data base is then replaced with the modified copy. This is an inefficient method of
/// changing a single user role, and so is a candidate for optimising.
void AuthenticationRepository::ChangeUserRole(const std::string& userID, const Role role, const User& user) const
{
   PermissionChecker permissionChecker;

   if (!permissionChecker.CheckPermission(ResourceType::Settings, user.GetRole(), AccessLevel::Full))
   {
      throw SecurityException("Unauthorised access to system settings.");
   }

   std::stringstream stringStream;
   std::ifstream inputFileStream("UserDatabase.txt");
   SecureString repositoryUserID, reposistoryRole, salt, hashedPassword;

   // [D18] Checking file stream before and after use

   if (inputFileStream.fail())
   {
      throw SecurityException("Unable to access user database.");
   }

   while (inputFileStream >> repositoryUserID >> reposistoryRole >> salt >> hashedPassword)
   {
      if (repositoryUserID.GetValue() == userID)
      {
         stringStream << repositoryUserID.GetValue() << " " << static_cast<int>(role) << " " << salt.GetValue() << " " << hashedPassword.GetValue() << std::endl;
      }
      else
      {
         stringStream << repositoryUserID.GetValue() << " " << reposistoryRole.GetValue() << " " << salt.GetValue() << " " << hashedPassword.GetValue() << std::endl;
      }
   }

   if (!inputFileStream.good())
   {
      throw SecurityException("Error when reading from user database.");
   }

   std::ofstream ofStream("UserDatabase.txt");

   // If file could be opened
   if (!ofStream.fail())
   {
      // If file could be written to
      if (ofStream << stringStream.str())
      {
         // If none of the error flags were set on the stream
         if (ofStream.good())
         {
            // Write was successful
         }
      }
   }
}

UserDetails AuthenticationRepository::GetUserDetails(const SecureString& userID)
{
   std::ifstream inputFileStream("UserDatabase.txt");
   SecureString repositoryUserID, role, salt, hashedPassword;

   if (inputFileStream.fail())
   {
      throw SecurityException("Unable to access user database.");
   }

   while (inputFileStream >> repositoryUserID >> role >> salt >> hashedPassword)
   {
      if (repositoryUserID == userID)
      {
         return UserDetails(hashedPassword, salt, ConvertStringToRole(role));
      }
   }

   if (!inputFileStream.good())
   {
      throw SecurityException("Error when reading from user database.");
   }

   return UserDetails();
}

SecureString AuthenticationRepository::GenerateSessionID()
{
   const int32_t sessionIDLength = 128;
   m_validSessionID = Random::GetRandom(sessionIDLength);
   return m_validSessionID;
}

Role AuthenticationRepository::ConvertStringToRole(const SecureString& string)
{
   Role role = Role::Unauthorised;
   const int32_t correctLengthOfRoleString = 1;

   if (string.GetLength() == correctLengthOfRoleString)
   {
      switch (string.GetValue()[0])
      {
         case '0': role = Role::Unauthorised; break;
         case '1': role = Role::Analyst; break;
         case '2': role = Role::Operator; break;
         case '3': role = Role::Director; break;
         default: throw SecurityException("Unrecognised role character found in user database.");
      }
   }
   else
   {
      throw SecurityException("Role string was in incorrect format.");
   }

   return role;
}
     