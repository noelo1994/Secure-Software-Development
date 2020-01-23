#include "SolarRadiationSimulator.h"
#include "Random.h"
#include "SecureInt32.h"

SolarRadiationSimulator::SolarRadiationSimulator() : Sensor(std::chrono::milliseconds(1500))
{
   // Implicit cast to double from int32_t is ok
   m_reading = Random::GetRandom(0, m_maxExpectedRadiation).GetValue();
}

void SolarRadiationSimulator::TakeReading()
{
   const SecureDouble maxChange = 50;
   SecureDouble newReading = m_reading + Random::GetRandom(-maxChange, maxChange);

   if (newReading.GetValue() > m_maxExpectedRadiation)
   {
      newReading = m_maxExpectedRadiation;
   }
   else if (newReading.GetValue() < 0)
   {
      newReading = 0;
   }

   m_reading = newReading;
}
