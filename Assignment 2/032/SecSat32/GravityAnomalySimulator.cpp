#include "GravityAnomalySimulator.h"
#include "Random.h"
#include "SecureInt32.h"

GravityAnomalySimulator::GravityAnomalySimulator() : 
Sensor(std::chrono::milliseconds(1000))
{
   // Implicit cast to double from int32_t is ok
   m_reading = Random::GetRandom(m_minExpectedAnomaly, m_maxExpectedAnomaly).GetValue();
}

void GravityAnomalySimulator::TakeReading()
{
   const SecureDouble maxChange = 20;
   SecureDouble newReading = m_reading + Random::GetRandom(-maxChange, maxChange);
 
   if (newReading.GetValue() > m_maxExpectedAnomaly)
   {
      newReading = m_maxExpectedAnomaly;
   }
   else if (newReading.GetValue() < m_minExpectedAnomaly)
   {
      newReading = m_minExpectedAnomaly;
   }

   m_reading = newReading;
}
