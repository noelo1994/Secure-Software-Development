#include "AuthenticationFactory.h"
#include "AuthenticationRepository.h"
#include "PermissionChecker.h"

std::unique_ptr<AuthenticationRepository> AuthenticationFactory::CreateAuthenticationRepository() const
{
   return std::make_unique<AuthenticationRepository>(AuthenticationRepository());
}

std::unique_ptr<PermissionChecker> AuthenticationFactory::CreatePermissionChecker() const
{
   return std::make_unique<PermissionChecker>(PermissionChecker());
}
