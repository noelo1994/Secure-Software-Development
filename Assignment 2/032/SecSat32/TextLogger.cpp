#include <fstream>
#include "TextLogger.h"

void TextLogger::Log(const std::string& message)
{
   std::ofstream fileStream("SensorLog.log", std::fstream::out | std::ios::app);

   // [DR2] Multiple checks are used to determine if the write was successful.
   // Any handling of the situation can easily be added and the checks are useful for debugging.

   // If file could be opened
   if (!fileStream.fail())
   {
      // If file could be written to
      if (fileStream << message)
      {
         // If none of the error flags were set on the stream
         if (fileStream.good())
         {
            // Write was successful
         }
      }
   }
}
