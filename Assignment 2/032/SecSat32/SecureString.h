#pragma once

#include <string>
#include "SecurityException.h"

/// A string class that ensures that internal sensitive information is cleared upon destruction. 
class SecureString
{
public:
   SecureString();
   SecureString(const rsize_t size, const char* const value);
   SecureString(const SecureString& secureString);
   ~SecureString();

   SecureString& operator=(const SecureString rhs);
   SecureString& operator+=(const char& rhs);
   SecureString& operator+=(const SecureString& rhs);

   const char* GetValue() const { return m_string; }
   rsize_t GetLength() const;
   void SetValue(const rsize_t size, const char* const value);
   void Clear();

   static const rsize_t MaxSize = 200; // Capable of holding the largest strings used in this application

private:
   void AddChar(const char character);

   const char m_nullTerminator = '\0';
   char* m_string = nullptr;
};

inline std::istream& operator >> (std::istream& inStream, SecureString& string)
{
   size_t newLength = 0;
   char inString[SecureString::MaxSize + 1];
   inStream >> inString;

   // Check that string is null terminated, and find the size of the string
   while (*(inString + newLength))
   {
      ++newLength;

      if (newLength > SecureString::MaxSize)
      {
         throw SecurityException("String from stream was not null terminated or was too long to be stored in a SecureString.");
      }
   }

   string.SetValue(newLength, inString);
   return inStream;
}

inline SecureString operator+(SecureString lhs, const SecureString& rhs)
{
   lhs += rhs;
   return lhs;
}

inline SecureString operator+(SecureString lhs, const char& rhs)
{
   lhs += rhs;
   return lhs;
}

inline bool operator==(const SecureString& lhs, const SecureString& rhs)
{
   // Because we are dealing with SecureStrings, we can guarantee that the strings will be null terminated
   return strcmp(lhs.GetValue(), rhs.GetValue()) == 0;
}
