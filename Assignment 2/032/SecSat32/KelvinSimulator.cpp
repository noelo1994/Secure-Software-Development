#include "KelvinSimulator.h"
#include "Random.h"
#include "SatelliteModel.h"
#include "UnitConverter.h"
#include "SecureDouble.h"

KelvinSimulator::KelvinSimulator(const ActiveThermalControlSystem* const activeThermalControlSystem) :
Sensor(std::chrono::milliseconds(500)),
m_activeThermalControlSystem(activeThermalControlSystem)
{
   m_reading = Random::GetRandom
   (UnitConverter::DegreesCelsiusToKelvin(SatelliteModel::MinOperatingTemperatureDegreesCelsius),
      UnitConverter::DegreesCelsiusToKelvin(SatelliteModel::MaxOperatingTemperatureDegreesCelsius));
}

void KelvinSimulator::TakeReading()
{
   SecureDouble newReading = m_reading;

   if (m_activeThermalControlSystem->GetIsActive())
   {
      const SecureDouble maxChange = 12;
      static const SecureDouble targetReading = UnitConverter::DegreesCelsiusToKelvin
         (SatelliteModel::MinOperatingTemperatureDegreesCelsius +
            (SatelliteModel::MaxOperatingTemperatureDegreesCelsius / 2));
    
      if (m_reading.GetValue() > targetReading.GetValue())
      {
         newReading -= Random::GetRandom(0, maxChange);
      }
      else if (m_reading.GetValue() < targetReading.GetValue())
      {
         newReading += Random::GetRandom(0, maxChange);
      }
      
   }
   else
   {
      const SecureDouble maxChange = 50;
      const SecureDouble minimumExpectedTemperatureOfASatelliteInALowEarthOrbit = 93.15;
      const SecureDouble maximumExpectedTemperatureOfASatelliteInALowEarthOrbit = 398.15;
     
      newReading += Random::GetRandom(-maxChange, maxChange);

      if (newReading.GetValue() > maximumExpectedTemperatureOfASatelliteInALowEarthOrbit.GetValue())
      {
         newReading = maximumExpectedTemperatureOfASatelliteInALowEarthOrbit;
      }
      else if (newReading.GetValue() < minimumExpectedTemperatureOfASatelliteInALowEarthOrbit.GetValue())
      {
         newReading = minimumExpectedTemperatureOfASatelliteInALowEarthOrbit;
      }
   }

   m_reading = newReading.GetValue();
}
