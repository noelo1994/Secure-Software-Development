#pragma once

#include <memory>
#include "SatelliteModelLogger.h"

class User;

/// Used to obtain a SatelliteModel that has a SatelliteModelLogger registered as one of its observers.
class LoggedSatelliteModelFactory
{
public:
   /// Returns a new SatelliteModel which is being observed by the static SatelliteModelLogger.
   std::unique_ptr<SatelliteModel> CreateLoggedSatelliteModel() const;

   /// Changes the type of the static SatelliteModelLogger.
   static void ChangeLoggerType(const LoggerType newLoggerType, const LogFormatType newLogFormatType, const User& user);

private:
   static SatelliteModelLogger m_logger;
};
