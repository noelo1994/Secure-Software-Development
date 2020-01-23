#include "UserDetails.h"
#include "Role.h"

UserDetails::UserDetails() : m_role(Role::Unauthorised), m_isValid(false)
{
}

UserDetails::UserDetails(const SecureString& hashedPassword, const SecureString& salt, const Role role) :
   m_hashedPassword(hashedPassword), m_salt(salt), m_role(role), m_isValid(true)
{
}

UserDetails::UserDetails(const UserDetails& userDetails) :
   m_hashedPassword(userDetails.m_hashedPassword), m_salt(userDetails.m_salt),
   m_role(userDetails.m_role), m_isValid(userDetails.m_isValid)
{
}
