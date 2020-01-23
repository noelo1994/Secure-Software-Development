#include "CppUnitTest.h"
#include "UnitConverter.h"
#include "SecureDouble.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SecureSatellite32Tests
{
   TEST_CLASS(UnitConverterTests)
   {
   public:
      TEST_METHOD(UnitConverter_WhenKelvinToDegreesCelsiusWithAbsoluteZero_ThenResultIsCorrect)
      {
         const auto absoluteZeroDegreesCelsius = SecureDouble(-273.15);
         
         auto convertedValue = UnitConverter::KelvinToDegreesCelsius(0);

         Assert::AreEqual(absoluteZeroDegreesCelsius.GetValue(), convertedValue.GetValue(), m_tolerance);
      }

      TEST_METHOD(UnitConverter_WhenKelvinToDegreesCelsiusWithPositiveKelvin_ThenResultIsCorrect)
      {
         const auto positiveValueKelvin = SecureDouble(205.4);
         const auto positiveValueDegreesCelsius = SecureDouble(-67.75);

         auto convertedValue = UnitConverter::KelvinToDegreesCelsius(positiveValueKelvin);

         Assert::AreEqual(positiveValueDegreesCelsius.GetValue(), convertedValue.GetValue(), m_tolerance);
      }

      TEST_METHOD(UnitConverter_WhenKelvinToDegreesCelsiusWithNegativeKelvin_ThenResultIsCorrect)
      {
         const auto negativeValueKelvin = SecureDouble(-75.35);
         const auto negativeValueDegreesCelsius = SecureDouble(-348.5);

         auto convertedValue = UnitConverter::KelvinToDegreesCelsius(negativeValueKelvin);

         Assert::AreEqual(negativeValueDegreesCelsius.GetValue(), convertedValue.GetValue(), m_tolerance);
      }

      TEST_METHOD(UnitConverter_WhenDegreesCelsiusToKelvinWithZeroDegrees_ThenResultIsCorrect)
      {
         const auto zeroDegreesCelsiusInKelvin = SecureDouble(273.15);
      
         auto convertedValue = UnitConverter::DegreesCelsiusToKelvin(0);

         Assert::AreEqual(zeroDegreesCelsiusInKelvin.GetValue(), convertedValue.GetValue(), m_tolerance);
      }

      TEST_METHOD(UnitConverter_WhenDegreesCelsiusToKelvinWithPositiveDegrees_ThenResultIsCorrect)
      {
         const auto positiveValueDegreesCelsius = SecureDouble(200.34);
         const auto positiveValueKelvin = SecureDouble(473.49);

         auto convertedValue = UnitConverter::DegreesCelsiusToKelvin(positiveValueDegreesCelsius);

         Assert::AreEqual(positiveValueKelvin.GetValue(), convertedValue.GetValue(), m_tolerance);
      }

      TEST_METHOD(UnitConverter_WhenDegreesCelsiusToKelvinWithNegativeDegrees_ThenResultIsCorrect)
      {
         const auto positiveValueDegreesCelsius = SecureDouble(-11.13);
         const auto positiveValueKelvin = SecureDouble(262.02);

         auto convertedValue = UnitConverter::DegreesCelsiusToKelvin(positiveValueDegreesCelsius);

         Assert::AreEqual(positiveValueKelvin.GetValue(), convertedValue.GetValue(), m_tolerance);
      }

   private:
      static constexpr double m_tolerance = 0.001;
   };
}