#include "ActiveThermalControlSystem.h"
#include "User.h"
#include "AccessLevel.h"
#include "PermissionChecker.h"
#include "ResourceType.h"

void ActiveThermalControlSystem::SetIsActive(const bool isActive, const User& user)
{
   PermissionChecker permissionChecker;

   if (!permissionChecker.CheckPermission(ResourceType::ActiveThermalControlSystem, user.GetRole(), AccessLevel::Full))
   {
      throw SecurityException("Unauthorised access to ActiveThermalControlSystem.");
   }

   m_isActive = isActive;
}
