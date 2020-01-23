#include "CppUnitTest.h"
#include "SecurityException.h"
#include "SecureString.h"
#include "Cryptography.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SecureSatellite32Tests
{
   TEST_CLASS(CrytograhpyTests)
   {
   public:
      TEST_METHOD(Cryptography_WhenHashString_ThenOriginalStringIsDifferentToHashedString)
      {
         auto const originalString = "testString";
         SecureString toHash(10, originalString);

         auto hashedString = Cryptography::HashString(toHash);

         Assert::AreNotEqual(originalString, hashedString.GetValue());
      }
   };
}