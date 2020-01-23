#include <sstream>
#include "SatelliteModelLogger.h"
#include "SatelliteModel.h"
#include "LoggerFactory.h"

SatelliteModelLogger::SatelliteModelLogger(const LoggerType loggerType, const LogFormatType logFormatType) : 
m_satelliteModel()
{
   LoggerFactory loggerFactory;
   std::unique_ptr<ILogger> logger = loggerFactory.CreateLogger(loggerType);
   m_logger = std::make_unique<LoggerDecorator>(move(logger), logFormatType);

   m_timer.SetOnElapsed([=]()
   {
      Log();
   });

   m_timer.Start(std::chrono::milliseconds(m_timerInterval));
}

void SatelliteModelLogger::Update(const Subject* const)
{
   std::stringstream stream;

   // The only subject being observed should be the satellite model
   stream << "Temp (°C): " << m_satelliteModel->GetTemperature().GetValue() << " | ";
   stream << "Solar Rad. (W/m²): " << m_satelliteModel->GetSolarRadiationReading().GetValue() << " | ";
   stream << "Grav. Anomaly (mGal): " << m_satelliteModel->GetGravityAnomalyReading().GetValue() << " | ";
   stream << "ATCS Status: " << (m_satelliteModel->GetActiveThermalControlSystemStatus() ? "On" : "Off") << " | ";
   stream << "Outside Operational Temp: " << (m_satelliteModel->GetIsOutOfOperatingTemperatureRange() ? "Yes" : "No") << " | ";
   stream << "Operational: " << (m_satelliteModel->GetIsOperational() ? "Yes" : "No") << "\n";

   // Lock the mutex while adding to the collection
   std::lock_guard<std::mutex> lock(m_logDataMutex);
   m_logData.emplace(stream.str());
}

void SatelliteModelLogger::SetLogger(const LoggerType loggerType, const LogFormatType logFormatType)
{
   m_timer.Stop();

   // Lock mutex so that the logger is not used while it is being changed
   std::lock_guard<std::mutex> lock(m_logDataMutex);

   LoggerFactory loggerFactory;
   std::unique_ptr<ILogger> logger = loggerFactory.CreateLogger(loggerType);

   // Calling reset on the smart pointer before reassigning it prevents the memory it is pointing to from being leaked
   // [DR1]
   m_logger.reset();
   m_logger = std::make_unique<LoggerDecorator>(move(logger), logFormatType);

   m_timer.Start(m_timerInterval);
}

void SatelliteModelLogger::Log()
{
   // Lock mutex so that the collection cannot be added to and the logger won't be changed while it's being used
   std::lock_guard<std::mutex> lock(m_logDataMutex);

   while (!m_logData.empty())
   {
      std::string logEntry = m_logData.front();
      m_logger->Log(logEntry);
      m_logData.pop();
   }
}
