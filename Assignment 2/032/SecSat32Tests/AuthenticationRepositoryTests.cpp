#include "CppUnitTest.h"
#include "AuthenticationRepository.h"
#include "SecureString.h"
#include "User.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SecureSatellite32Tests
{
   TEST_CLASS(AuthenticationRepositoryTests)
   {
   public:
      TEST_METHOD(AuthenticationRepository_WhenValidateUserWithValidUserIDAndPassword_ThenUserIsValidated)
      {
         const auto numberOfUsersToTest = 6;
         const char* const userIDs[numberOfUsersToTest]
         {
            "AldrinE",
            "ArmstrongN",
            "ConradP",
            "DevP",
            "KulonJ",
            "PlassmannP"
         };

         const char* const passwords[numberOfUsersToTest]
         {
            "Fortune59Fairs13Dilemmas",
            "Siegmund92Dismayed95Painful",
            "Wielded65brothels54archly",
            "Reviver71Starred18precise",
            "Eligible12Tanya33Lawsuits",
            "wager13Diode11Swam",
         };

         for (auto index = 0; index < numberOfUsersToTest; ++index)
         {
            SecureString username(strlen(userIDs[index]), userIDs[index]);
            SecureString password(strlen(passwords[index]), passwords[index]);
            AuthenticationRepository authenticationRepository;
            auto user = authenticationRepository.CreateUser(username, password);
            Assert::IsTrue(authenticationRepository.ValidateUserSessionID(user));
         }
      }
   };
}