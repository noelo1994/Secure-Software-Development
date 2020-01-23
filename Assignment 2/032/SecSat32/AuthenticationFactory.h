#pragma once

#include <memory>

class AuthenticationRepository;
class PermissionChecker;

/// Allows simplification of constructors, removing responsibility from clients.
class AuthenticationFactory
{
public:
   /// Returns a new authentication repository.
   std::unique_ptr<AuthenticationRepository> CreateAuthenticationRepository() const;

   /// Returns a new permission checker.
   std::unique_ptr<PermissionChecker> CreatePermissionChecker() const;
};
