#pragma once

#include <queue>
#include <mutex>
#include "IObserver.h"
#include "Timer.h"
#include "LoggerDecorator.h"

class SatelliteModel;
enum class LogFormatType;
enum class LoggerType;

/// Responsible for monitoring the SatelliteModel and logging the data it provides.
class SatelliteModelLogger : public IObserver
{
public:
   SatelliteModelLogger(const LoggerType loggerType, const LogFormatType logFormatType);

   /// Adds data to be logged to a collection.
   void Update(const Subject* const) override;

   void SetModel(SatelliteModel* model) { m_satelliteModel = model; };

   /// Allows the type of logger being used to be changed.
   void SetLogger(const LoggerType loggerType, const LogFormatType logFormatType);

private:

   /// Logs the data to be logged, removing it from the collection.
   void Log();

   const std::chrono::milliseconds m_timerInterval = std::chrono::milliseconds(30000);
   std::unique_ptr<LoggerDecorator> m_logger;
   Timer m_timer;
   std::mutex m_logDataMutex;
   SatelliteModel* m_satelliteModel;
   std::queue<std::string> m_logData;
};

