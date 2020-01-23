#include "LoginResult.h"

LoginResult::LoginResult() : m_isSuccess(false), m_user()
{
}

LoginResult::LoginResult(const User user) : m_isSuccess(true), m_user(user)
{
}

LoginResult::LoginResult(const LoginResult& loginResult) : 
m_isSuccess(loginResult.m_isSuccess), m_user(loginResult.m_user)
{
}