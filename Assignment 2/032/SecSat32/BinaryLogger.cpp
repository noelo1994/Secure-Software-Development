#include <fstream>
#include <sstream>
#include <bitset>
#include "BinaryLogger.h"

void BinaryLogger::Log(const std::string& message)
{
   std::stringstream stringStream;

   // Convert string characters to hexadecimal
   for (const int8_t character : message)
   {
      stringStream << std::bitset<CHAR_BIT>(character);
   }

   std::ofstream fileStream("SensorLog.log", std::fstream::out | std::ios::app, std::ios_base::binary);

   // If file could be opened
   if (!fileStream.fail())
   {
      // If file could be written to
      if (fileStream << stringStream.str())
      {
         // If none of the error flags were set on the stream
         if (fileStream.good())
         {
            // Write was successful
         }
      }
   }
}
