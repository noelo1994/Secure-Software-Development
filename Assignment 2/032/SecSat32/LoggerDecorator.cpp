#include <sstream>
#include "LoggerDecorator.h"
#include "LogFormatType.h"
#include "Cryptography.h"
#include "SecureString.h"

LoggerDecorator::LoggerDecorator(std::unique_ptr<ILogger>& logger, const LogFormatType formatType) : 
m_logger(move(logger)), m_formatType(formatType)
{
}

std::string LoggerDecorator::FormatMessage(const std::string& message) const
{
   std::string formattedMessage = message;

   switch (m_formatType)
   {
      case LogFormatType::Encrypted: formattedMessage = EncryptDecrypt(message); break;
      case LogFormatType::Plain:
      default: break;
   }

   return formattedMessage;
}

void LoggerDecorator::Log(const std::string& message)
{
   std::string formattedMessage = FormatMessage(message);
   m_logger->Log(formattedMessage);
}

std::string LoggerDecorator::EncryptDecrypt(const std::string& message)
{
   return Cryptography::EncryptDecrypt(message, 'D').GetValue();
}
