#include "LoggerFactory.h"
#include "TextLogger.h"
#include "BinaryLogger.h"
#include "LoggerType.h"
#include "SecurityException.h"

std::unique_ptr<ILogger> LoggerFactory::CreateLogger(const LoggerType loggerType) const
{
   switch (loggerType)
   {
      case LoggerType::Text: return std::make_unique<TextLogger>();
      case LoggerType::Binary: return std::make_unique<BinaryLogger>();
      default:                 throw SecurityException("Logger type was not recognised.");
   }
}
