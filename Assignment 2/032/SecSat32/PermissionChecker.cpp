#include "PermissionChecker.h"
#include "AccessLevel.h"
#include "Role.h"

PermissionChecker::PermissionChecker()
{
   // Resource Type:                     ATCS               SelfDestruct       Settings
   m_accessTable[Role::Unauthorised] = { AccessLevel::None, AccessLevel::None, AccessLevel::None };
   m_accessTable[Role::Analyst] = { AccessLevel::Readonly, AccessLevel::None, AccessLevel::None };
   m_accessTable[Role::Operator] = { AccessLevel::Full, AccessLevel::None, AccessLevel::Readonly };
   m_accessTable[Role::Director] = { AccessLevel::Full, AccessLevel::Full, AccessLevel::Full };
}

bool PermissionChecker::CheckPermission(const ResourceType resource, const Role role, const AccessLevel accessLevel)
{
   bool hasPermission = false;

   if (m_accessTable[role].at(static_cast<int32_t>(resource)) == accessLevel)
   {
      hasPermission = true;
   }

   return hasPermission;
}
