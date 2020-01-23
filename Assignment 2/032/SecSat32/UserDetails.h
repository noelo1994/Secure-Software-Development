#pragma once

#include "SecureString.h"

enum class Role;

/// Holds details about a user, as they are stored in the database.
struct UserDetails
{
public:
   UserDetails();
   UserDetails(const SecureString& hashedPassword, const SecureString& salt, const Role accessLevel);
   UserDetails(const UserDetails& userDetails);

   SecureString GetHashedPassword() const { return m_hashedPassword; }
   SecureString GetSalt() const { return m_salt; }
   Role GetRole() const { return m_role; }
   bool GetIsValid() const { return m_isValid; }

private:
   const SecureString m_hashedPassword;
   const SecureString m_salt;
   const Role m_role;
   const bool m_isValid;
};
