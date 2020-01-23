#include "SecureUInt32.h"
#include "SecurityException.h"

SecureUInt32::SecureUInt32() : m_value(0)
{
}

SecureUInt32::SecureUInt32(const uint32_t value) : m_value(value)
{
}

SecureUInt32& SecureUInt32::operator=(const uint32_t rhs)
{
   m_value = rhs;
   return *this;
}

SecureUInt32& SecureUInt32::operator++()
{
   if (m_value == (UINT32_MAX - 1))
   {
      throw SecurityException("Wrap in SecureUInt32 operation.");
   }

   ++m_value;
   return *this;
}

SecureUInt32& SecureUInt32::operator+=(const rsize_t rhs)
{
   uint64_t largerType = m_value;
   largerType += rhs;

   if (largerType > UINT32_MAX)
   {
      throw SecurityException("Wrap in SecureUInt32 operation.");
   }

   m_value += rhs;
   return *this;
}
