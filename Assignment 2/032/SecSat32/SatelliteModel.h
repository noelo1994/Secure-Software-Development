#pragma once

#include <memory>
#include "IObserver.h"
#include "Subject.h"
#include "SecureDouble.h"
#include "ActiveThermalControlSystem.h"

class Sensor;

/// Responsible for holding the state of the satellite.
class SatelliteModel : public Subject, IObserver
{
public:
   SatelliteModel();
   void StartReadings() const;
   SecureDouble GetTemperature() const { return m_temperature; }
   SecureDouble GetSolarRadiationReading() const { return m_solarRadiationReading; }
   SecureDouble GetGravityAnomalyReading() const { return m_gravityAnomalyReading; }
   bool GetIsOperational() const { return m_isOperational; }
   bool GetIsOutOfOperatingTemperatureRange() const { return m_IsOutOfOperatingTemperatureRange; }
   bool GetActiveThermalControlSystemStatus() const { return m_activeThermalControlSystem.GetIsActive(); }
   void ToggleActiveThermalControl(const User& user);
   void SelfDestruct(const User& user);
   void Update(const Subject* const subject) override;

   // Typical operational temperature range of batteries
   static constexpr double MinOperatingTemperatureDegreesCelsius = -5;
   static constexpr double MaxOperatingTemperatureDegreesCelsius = 20;

private:
   ActiveThermalControlSystem m_activeThermalControlSystem;
   const std::unique_ptr<Sensor> m_kelvinSimulator;
   const std::unique_ptr<Sensor> m_solarRadiationSimulator;
   const std::unique_ptr<Sensor> m_gravityAnomalySimulator;
   SecureDouble m_temperature = 0;
   SecureDouble m_solarRadiationReading = 0;
   SecureDouble m_gravityAnomalyReading = 0;
   bool m_isOperational = true;
   bool m_IsOutOfOperatingTemperatureRange = false;
};

