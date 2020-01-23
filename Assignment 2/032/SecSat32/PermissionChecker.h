#pragma once

#include <map>
#include <vector>

enum class ResourceType;
enum class AccessLevel;
enum class Role;

/// Responsible for holding and providing information about which users have access to which resources.
class PermissionChecker
{
public:
   PermissionChecker();

   /// Returns true if the given role has the given access level for the given resource type.
   bool CheckPermission(const ResourceType resource, const Role role, const AccessLevel);

private:
   std::map<Role, std::vector<AccessLevel>> m_accessTable;
};
