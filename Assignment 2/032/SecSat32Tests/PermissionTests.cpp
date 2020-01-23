#include "CppUnitTest.h"
#include "Timer.h"
#include "PermissionChecker.h"
#include "AccessLevel.h"
#include "ResourceType.h"
#include "Role.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SecureSatellite32Tests
{
   TEST_CLASS(PermissionTests)
   {
   public:
      TEST_METHOD(Permission_WhenCheckPermissionForDirector_ThenDirectorHasFullAccessToAllResources)
      {
         PermissionChecker permissionChecker;

         Assert::IsTrue(permissionChecker.CheckPermission(ResourceType::ActiveThermalControlSystem, Role::Director, AccessLevel::Full));
         Assert::IsTrue(permissionChecker.CheckPermission(ResourceType::SelfDestruct, Role::Director, AccessLevel::Full));
         Assert::IsTrue(permissionChecker.CheckPermission(ResourceType::Settings, Role::Director, AccessLevel::Full));
      }

      TEST_METHOD(Permission_WhenCheckPermissionForUnauthorised_ThenUnauthorisedHasNoAccessToResources)
      {
         PermissionChecker permissionChecker;

         Assert::IsTrue(permissionChecker.CheckPermission(ResourceType::ActiveThermalControlSystem, Role::Unauthorised, AccessLevel::None));
         Assert::IsTrue(permissionChecker.CheckPermission(ResourceType::SelfDestruct, Role::Unauthorised, AccessLevel::None));
         Assert::IsTrue(permissionChecker.CheckPermission(ResourceType::Settings, Role::Unauthorised, AccessLevel::None));
      }
   };
}