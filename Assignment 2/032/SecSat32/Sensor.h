#pragma once

#include "Timer.h"
#include "SecureDouble.h"
#include "Subject.h"

/// Base class for all sensors.
class Sensor : public Subject
{
public:
   explicit Sensor(const std::chrono::milliseconds& readingInterval);
   virtual ~Sensor()
   {
   }

   SecureDouble GetReading() const { return m_reading; }
   void BeginMonitoring();
   void CeaseMonitoring();

protected:
   virtual void TakeReading() = 0;

   const std::chrono::milliseconds m_readingInterval;
   SecureDouble m_reading;
   Timer m_timer;
};
