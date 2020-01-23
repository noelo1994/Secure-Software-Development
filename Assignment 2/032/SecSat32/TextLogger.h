#pragma once

#include <string>
#include "ILogger.h"

/// Logs using human-readable characters.
class TextLogger : public ILogger
{
public:
   void Log(const std::string& message) override;
};
