#include "CppUnitTest.h"
#include <SecureInt32.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SecureSatellite32Tests
{
   TEST_CLASS(SecureIntTests)
   {
   public:
      TEST_METHOD(SecureInt_WhenDefaultConstruction_ThenValueIsZero)
      {
         SecureInt32 secureInt;

         Assert::AreEqual(0, secureInt.GetValue());
      }
   };
}