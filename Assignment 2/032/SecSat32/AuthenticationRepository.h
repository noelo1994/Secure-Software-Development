#pragma once

#include <string>

class SecureString;
class User;
struct UserDetails;
enum class Role;

/// Responsible for accessing and using information from the user database.
/// Also keeps the record of the valid session ID.
class AuthenticationRepository
{
public: 
   AuthenticationRepository();

   /// Checks that the given user ID and password combination exists in the database.
   /// The returned object will have a valid session ID only if the details were valid.
   User CreateUser(const SecureString& userID, const SecureString& password) const;

   /// Checks whether or not the given user has a valid session ID.
   bool ValidateUserSessionID(const User& user) const;

   /// Gets a list of all users in the database, and their roles. Throws if the requesting user has an
   /// insufficient access level.
   SecureString GetListOfUsersAndRoles(const User& user);

   /// Changes the role of the provided user ID. Throws if the requesting user has an insufficient access level.
   void ChangeUserRole(const std::string& userID, const Role role, const User& user) const;

private:

   /// Gets user details from the database, given a user ID.
   /// The returned object will be invalid if no user was found (can be checked by a property on the object).
   static UserDetails GetUserDetails(const SecureString& userID);

   /// Generates a random string and sets m_validSessionID with the value
   static SecureString GenerateSessionID();

   /// Outputs the corresponding role when given a string.
   /// Throws if there was not corresponding role.
   static Role ConvertStringToRole(const SecureString& string);

   static SecureString m_validSessionID;
};
