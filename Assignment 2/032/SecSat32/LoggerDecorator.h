#pragma once

#include <memory>
#include "ILogger.h"

enum class LogFormatType;

/// Allows a log format type to be chosen for any logger.
class LoggerDecorator : public ILogger
{
public:
   LoggerDecorator(std::unique_ptr<ILogger>& logger, const LogFormatType formatType);

   /// Formats the message depending on the format type given at construction.
   std::string FormatMessage(const std::string& message) const;

   void Log(const std::string& message) override;

private:
  static std::string EncryptDecrypt(const std::string& toEncrypt);

   const std::unique_ptr<ILogger> m_logger;
   const LogFormatType m_formatType;
};
