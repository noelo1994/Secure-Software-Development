#pragma once

#include "Subject.h"

class SecureDouble;
enum class SatelliteViewUserRequestedAction;

/// Allows abstraction of a satellite view.
class ISatelliteView : public Subject
{
public:
   virtual ~ISatelliteView()
   {
   }

   virtual bool Process() const = 0;
   virtual void SetSatelliteTemperatureReading(const SecureDouble& newReading) = 0;
   virtual void SetSolarRadiationReading(const SecureDouble& newReading) = 0;
   virtual void SetGravityAnomalyReading(const SecureDouble& newReading) = 0;
   virtual void ShowTemperatureWarning() const = 0;
   virtual void HideTemperatureWarning() const = 0;
   virtual void IndicateLostConnection() const = 0;
   virtual void IndicateATCSPermissionDenied() const = 0;
   virtual void IndicateSelfDestructPermissionDenied() const = 0;
   virtual void IndicateSettingsPermissionDenied() const = 0;
   virtual SatelliteViewUserRequestedAction GetUserRequestedAction() const = 0;
};
