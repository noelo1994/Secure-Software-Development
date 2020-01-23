#include "Sensor.h"

Sensor::Sensor(const std::chrono::milliseconds& readingInterval) : m_readingInterval(readingInterval)
{
   m_timer.SetOnElapsed([=]()
   {
      TakeReading();
      NotifyObservers();
   });
}

void Sensor::BeginMonitoring()
{
   m_timer.Start(m_readingInterval);
}

void Sensor::CeaseMonitoring()
{
   m_timer.Stop();
}
