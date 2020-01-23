#pragma once

#include "Sensor.h"

class ActiveThermalControlSystem;

/// Simulates the temperatures that a satellite in low earth orbit may experience.
class KelvinSimulator : public Sensor
{
public:
   explicit KelvinSimulator(const ActiveThermalControlSystem* const activeThermalControlSystem);

private:   
   void TakeReading() override;

   const ActiveThermalControlSystem* const m_activeThermalControlSystem;
};
