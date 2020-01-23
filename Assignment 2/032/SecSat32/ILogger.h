#pragma once

/// Interface for a logger.
class ILogger
{
public:
   virtual ~ILogger()
   {
   }

   virtual void Log(const std::string& message) = 0;
};
