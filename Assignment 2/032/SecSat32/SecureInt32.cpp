#include "SecureInt32.h"
#include "SecurityException.h"
#include "SecureUInt32.h"

SecureInt32::SecureInt32() : m_value(0)
{
}

SecureInt32::SecureInt32(const int32_t value) : m_value(value)
{
}

SecureInt32& SecureInt32::operator=(const int32_t rhs)
{
   m_value = rhs;
   return *this;
}

SecureInt32& SecureInt32::operator++()
{
   // [D5] Checking that incrementing the value will not cause overflow
   if (m_value == (INT32_MAX - 1))
   {
      throw SecurityException("Overflow in SecureInt32 operation.");
   }

   ++m_value;
   return *this;
}

SecureInt32& SecureInt32::operator+=(const rsize_t rhs)
{
   uint64_t largerType = m_value;
   largerType += rhs;

   // [D6] Checking that addition will not cause overflow
   if (largerType > INT32_MAX)
   {
      throw SecurityException("Overflow in SecureUInt32 operation.");
   }

   m_value += rhs;
   return *this;
}
