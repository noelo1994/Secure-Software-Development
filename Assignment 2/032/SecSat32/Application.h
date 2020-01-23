#pragma once

#include <cstdint>

/// Responsbile for handling the workflow of the program.
class Application
{
public:
   /// Runs the application. Returns 0 on success and 1 on failiure.
   int32_t Run() const;

private:
   static bool m_isRunning;
};
