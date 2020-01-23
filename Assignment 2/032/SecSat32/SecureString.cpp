#include "SecureString.h"
#include <Windows.h>
#include <memory>
#include "SecureUInt32.h"

SecureString::SecureString() : m_string(new char(m_nullTerminator))
{
}

SecureString::SecureString(const rsize_t size, const char* const value) : m_string(nullptr)
{
   SetValue(size, value);
}

SecureString::~SecureString() 
{
   Clear();
}

SecureString& SecureString::operator=(const SecureString rhs)
{
   SetValue(strlen(rhs.m_string), rhs.m_string);
   return *this;
}

SecureString& SecureString::operator+=(const SecureString& rhs)
{
   const rsize_t oldLength = GetLength(); 
   const SecureString temp(*this);
   const rsize_t newLength = oldLength + rhs.GetLength() + 1; // Plus one to account for null terminator
   m_string = new char[newLength];

   // Copy the old value into the new array, without the null terminator
   for (SecureUInt32 index; index.GetValue() < oldLength; ++index)
   {
      m_string[index.GetValue()] = temp.GetValue()[index.GetValue()];
   }

   // Append the new value onto the old, including the null terminator
   for (SecureUInt32 loop; (loop + oldLength).GetValue() < newLength; ++loop)
   {
      m_string[(loop + oldLength).GetValue()] = rhs.GetValue()[loop.GetValue()];
   }

   return *this;
}

SecureString& SecureString::operator+=(const char& rhs)
{
   AddChar(rhs);
   return *this;
}

SecureString::SecureString(const SecureString& secureString)
{
   SetValue(secureString.GetLength(), secureString.m_string);
}

rsize_t SecureString::GetLength() const
{
   // [D7] Using secure version of strnlen to determine the size of the string
   rsize_t currentStringSize = strnlen_s(m_string, MaxSize + 1);

   if (currentStringSize == MaxSize + 1)
   {
      throw SecurityException("SecureString is longer than allowed, or is without null terminator.");
   }

   return currentStringSize;
}

void SecureString::SetValue(const rsize_t size, const char* const value)
{
   if (size > MaxSize)
   {
      throw SecurityException("Attempted to set a SecureString to a value longer than allowed.");
   }

   // [D8] Deleting memory before reassignment to prevent memory leak
   Clear();

   m_string = new char[size + 1]; // Plus one to allow for null terminator

   for (SecureUInt32 index(0); index.GetValue() < size; ++index)
   {
      m_string[index.GetValue()] = value[index.GetValue()];
   }

   // [D9] Ensuring the string is null terminated
   m_string[size] = m_nullTerminator; 
}

void SecureString::AddChar(const char character)
{
   const rsize_t oldLength = GetLength(); 
   const SecureString temp(*this);
   const rsize_t newLength = oldLength + 2; // +2 to account for the null terminator and new character
   m_string = new char[newLength];

   // Copy the old value into the new array, without the null terminator
   for (SecureUInt32 index(0); index.GetValue() < oldLength; ++index)
   {
      m_string[index.GetValue()] = temp.GetValue()[index.GetValue()];
   }

   m_string[oldLength] = character;
   m_string[newLength - 1] = m_nullTerminator;
}

void SecureString::Clear()
{
   if (m_string)
   {
      // [D10] CERT MEM03-CPP (Clear sensitive information stored in returned reusable resources)
      // Clears memory, will not be optimised out by the compiler
      SecureZeroMemory(m_string, strlen(m_string)); 

      delete[] m_string;  // [D11] Correct use of delete[]
      m_string = nullptr; // [D12] Setting to nullptr to avoid dangling pointer
   }
}

