#pragma once

#include "ILogger.h"

/// Logs in binary format.
class BinaryLogger : public ILogger
{
   void Log(const std::string& message) override;
};
