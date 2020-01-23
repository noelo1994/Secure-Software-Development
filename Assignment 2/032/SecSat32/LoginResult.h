#pragma once

#include "User.h"

/// Holds data concerning a login attempt.
struct LoginResult
{
public:
   LoginResult();
   explicit LoginResult(const User user);
   LoginResult(const LoginResult& loginResult);

   bool GetIsSuccess() const { return m_isSuccess; }
   User GetUser() const { return m_user; }

private:
   bool m_isSuccess;
   User m_user;
};
