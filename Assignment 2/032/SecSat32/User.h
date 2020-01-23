#pragma once

#include "SecureString.h"
#include "Role.h"

/// Hold details about a user.
class User
{
public:
   SecureString GetSessionID() const { return m_sessionID; }
   void SetSessionID(const SecureString sessionID) { m_sessionID = sessionID; }
   Role GetRole() const { return m_role; }
   void SetRole(const Role role) { m_role = role; }

private:
   SecureString m_sessionID;
   Role m_role = Role::Unauthorised;
};
