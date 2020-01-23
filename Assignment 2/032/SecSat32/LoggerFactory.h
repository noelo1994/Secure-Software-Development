#pragma once

#include <memory>

class ILogger;
enum class LoggerType;

/// Creates loggers, removing responsibility from clients.
class LoggerFactory
{
public:
   /// Returns a different type of logger based on the type given.
   std::unique_ptr<ILogger> CreateLogger(const LoggerType loggerType) const;
};
