#include "SecureString.h"
#include <CppUnitTest.h>
#include "Random.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SecureSatellite32Tests
{
   TEST_CLASS(SecureStringTests)
   {
   public:
      TEST_METHOD(SecureString_WhenDefaultConstruction_ThenStringIsNullTerminated)
      {
         const size_t expectedLength = 0;

         SecureString string;

         Assert::AreEqual(expectedLength, strlen(string.GetValue()));
      }

      TEST_METHOD(SecureString_WhenConstructionWithString_ThenStringIsExpected)
      {
         const size_t expectedLength = 4;

         SecureString string(expectedLength, "User");

         Assert::AreEqual("User", string.GetValue());
      }

      TEST_METHOD(SecureString_WhenAssignment_ThenStringIsNullTerminated)
      {
         const size_t expectedLength = 2;
         SecureString string;

         string.SetValue(expectedLength, "hi");

         Assert::AreEqual(expectedLength, strlen(string.GetValue()));
      }

      TEST_METHOD(SecureString_WhenSetValue_ThenStringIsExpected)
      {
         const size_t expectedLength = 5;
         SecureString string;

         string.SetValue(expectedLength, "hello");

         Assert::AreEqual("hello", string.GetValue());
      }

      TEST_METHOD(SecureString_WhenSetValueWithNullTerminatedString_ThenStringIsExpected)
      {
         const size_t expectedLength = 6;
         SecureString string;
         const char nullTerminatedString[expectedLength]{ 'h', 'e', 'l', 'l', 'o', '\0' };

         string.SetValue(expectedLength, nullTerminatedString);

         Assert::AreEqual("hello", string.GetValue());
      }

      TEST_METHOD(SecureString_WhenAssignmentWithSmallerSizeThanValueBeingAssigned_ThenSizeDeterminesStringLength)
      {
         const size_t expectedLength = 6;
         SecureString string;

         string.SetValue(expectedLength, "A nice long string");

         Assert::AreEqual("A nice", string.GetValue());
      }

      TEST_METHOD(SecureString_WhenAssignmentWithSecureString_ThenStringIsExpected)
      {
         const size_t expectedLength = 6;
         SecureString string;

         string = SecureString(expectedLength, "hello!");

         Assert::AreEqual("hello!", string.GetValue());
      }

      TEST_METHOD(SecureString_WhenAdditionAssignmentWithchar_ThenStringIsExpectedValue)
      {
         const size_t expectedLength = 9;
         SecureString string(expectedLength,"123456789");

         string += 'P';

         Assert::AreEqual("123456789P", string.GetValue());
      }

      TEST_METHOD(SecureString_WhenAdditionAssignmentWithSecureString_ThenStringIsExpectedValue)
      {
         const size_t expectedLength = 9;
         SecureString string(expectedLength, "123456789");
         SecureString addedString(expectedLength, "987654321");

         string += addedString;

         Assert::AreEqual("123456789987654321", string.GetValue());
      }
   };
}