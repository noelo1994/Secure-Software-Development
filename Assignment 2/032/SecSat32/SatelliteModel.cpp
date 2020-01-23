#include "SatelliteModel.h"
#include "KelvinSimulator.h"
#include "SolarRadiationSimulator.h"
#include "GravityAnomalySimulator.h"
#include "UnitConverter.h"
#include "PermissionChecker.h"
#include "User.h"
#include "AccessLevel.h"
#include "ResourceType.h"

SatelliteModel::SatelliteModel() : 
m_kelvinSimulator(std::make_unique<KelvinSimulator>(&m_activeThermalControlSystem)),
m_solarRadiationSimulator(std::make_unique<SolarRadiationSimulator>()),
m_gravityAnomalySimulator(std::make_unique<GravityAnomalySimulator>())
{
   m_kelvinSimulator->RegisterObserver(this);
   m_solarRadiationSimulator->RegisterObserver(this);
   m_gravityAnomalySimulator->RegisterObserver(this);
}

void SatelliteModel::StartReadings() const
{
   m_kelvinSimulator->BeginMonitoring();
   m_solarRadiationSimulator->BeginMonitoring();
   m_gravityAnomalySimulator->BeginMonitoring();
}

void SatelliteModel::ToggleActiveThermalControl(const User& user)
{
   m_activeThermalControlSystem.SetIsActive(!m_activeThermalControlSystem.GetIsActive(), user);
}

void SatelliteModel::SelfDestruct(const User& user)
{
   PermissionChecker permissionChecker;

   if (!permissionChecker.CheckPermission(ResourceType::SelfDestruct, user.GetRole(), AccessLevel::Full))
   {
      throw SecurityException("Unauthorised access to SelfDestruct method of SatelliteModel.");
   }

   m_isOperational = false;
   m_activeThermalControlSystem.SetIsActive(false, user);
   m_kelvinSimulator->CeaseMonitoring();
   m_solarRadiationSimulator->CeaseMonitoring();
   m_gravityAnomalySimulator->CeaseMonitoring();
}

void SatelliteModel::Update(const Subject* const subject)
{
   const void* const subjectAddress = subject;

   if (subjectAddress == m_kelvinSimulator.get())
   {
      m_temperature = UnitConverter::KelvinToDegreesCelsius(m_kelvinSimulator->GetReading());

      if ((m_temperature.GetValue() < MinOperatingTemperatureDegreesCelsius) ||
         (m_temperature.GetValue() > MaxOperatingTemperatureDegreesCelsius))
      {
         m_IsOutOfOperatingTemperatureRange = true;
      }
      else
      {
         m_IsOutOfOperatingTemperatureRange = false;
      }
   }
   else if (subjectAddress == m_solarRadiationSimulator.get())
   {
      m_solarRadiationReading = m_solarRadiationSimulator->GetReading();
   }
   else if (subjectAddress == m_gravityAnomalySimulator.get())
   {
      m_gravityAnomalyReading = m_gravityAnomalySimulator->GetReading();
   }

   NotifyObservers();
}
