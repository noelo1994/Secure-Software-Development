#include "CppUnitTest.h"
#include "SecureDouble.h"
#include "SecurityException.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SecureSatellite32Tests
{
   TEST_CLASS(SecureDoubleTests)
   {
   public:
      TEST_METHOD(SecureDouble_WhenDefaultConstruction_ThenValueIsZero)
      {
         SecureDouble secureDouble;

         Assert::AreEqual(0.0, secureDouble.GetValue());
      }

      TEST_METHOD(SecureDouble_WhenConstructionWithInitialValue_ThenValueIsInitialValue)
      {
         const auto initialValue = 300.65735;
         SecureDouble secureDouble(initialValue);

         Assert::AreEqual(initialValue, secureDouble.GetValue());
      }

      TEST_METHOD(SecureDouble_WhenAssignmentToDouble_NewValueIsCorrect)
      {
         const auto newValue = 30630.7435;
         SecureDouble secureDouble;

         secureDouble = newValue;

         Assert::AreEqual(newValue, secureDouble.GetValue());
      }

      TEST_METHOD(SecureDouble_WhenAdditionAssignmentToDouble_NewValueIsCorrect)
      {
         const auto initialValue = 67.3834;
         const auto valueToAdd = 30630.7435;
         SecureDouble secureDouble(initialValue);

         secureDouble += valueToAdd;

         Assert::AreEqual(initialValue + valueToAdd, secureDouble.GetValue());
      }

      TEST_METHOD(SecureDouble_WhenAdditionAssignmentToDoubleOverflows_ThenThrowsSecurityException)
      {
         SecureDouble secureDouble(std::numeric_limits<double>::max());
   
         try
         {
            secureDouble += secureDouble.GetValue();
            Assert::Fail(L"Expected an exception.");
         }
         catch (const SecurityException& ex)
         {
            Assert::AreEqual("Overflow in SecureDouble operation.", ex.GetMessage());
         }
      }
   };
}