#pragma once

#include "Sensor.h"

/// Simulates the values provided by satellites monitoring gravity anomaly.
class GravityAnomalySimulator : public Sensor
{
public:
   GravityAnomalySimulator();

private:
   void TakeReading() override;

   static constexpr int32_t m_maxExpectedAnomaly = 70;
   static constexpr int32_t m_minExpectedAnomaly = -70;
};
