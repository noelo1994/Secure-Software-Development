#pragma once

#include "Sensor.h"

/// Simulates readings of solar radiation.
class SolarRadiationSimulator : public Sensor
{
public:
   SolarRadiationSimulator();

private:
   void TakeReading() override;

   static constexpr int32_t m_maxExpectedRadiation = 400;
};
