#include "UnitConverter.h"
#include "SecureDouble.h"

SecureDouble UnitConverter::KelvinToDegreesCelsius(const SecureDouble& kelvin)
{
   return SecureDouble(kelvin - m_zeroDegreesCelsiusInKelvin);
}

SecureDouble UnitConverter::DegreesCelsiusToKelvin(const SecureDouble& degreesCelsius)
{
   return SecureDouble(degreesCelsius + m_zeroDegreesCelsiusInKelvin);
}
