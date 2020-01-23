#pragma once

class SecureDouble;

/// Responsible for any unit conversions.
class UnitConverter
{
public:
   /// Outputs the inputted Kelvin value in Degrees Celsius.
   static SecureDouble KelvinToDegreesCelsius(const SecureDouble& kelvin);

   /// Outputs the inputted Degrees Celsius value in Kelvin.
   static SecureDouble DegreesCelsiusToKelvin(const SecureDouble& degreesCelsius);

private:
   static constexpr double m_zeroDegreesCelsiusInKelvin = 273.15;
};
