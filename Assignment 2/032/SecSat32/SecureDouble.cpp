#include <cfenv>
#include "SecureDouble.h"
#include "SecurityException.h"

SecureDouble::SecureDouble() : m_value(0)
{
}

SecureDouble::SecureDouble(const double intialValue) : m_value(intialValue)
{
}

SecureDouble& SecureDouble::operator=(const double rhs)
{
   m_value = rhs;
   return *this;
}

SecureDouble& SecureDouble::operator=(const SecureDouble rhs)
{
   m_value = rhs.GetValue();
   return *this;
}

SecureDouble& SecureDouble::operator-=(const double& rhs)
{
   ClearFlags();
   m_value -= rhs;
   ThrowIfOutOfRange();
   return *this;
}

SecureDouble& SecureDouble::operator-=(const SecureDouble& rhs)
{
   ClearFlags();
   m_value -= rhs.GetValue();
   ThrowIfOutOfRange();
   return *this;
}

SecureDouble SecureDouble::operator-() const
{
   ClearFlags();
   SecureDouble secureDouble = -m_value;
   ThrowIfOutOfRange();
   return secureDouble;
}

SecureDouble& SecureDouble::operator+=(const double& rhs)
{
   ClearFlags();
   m_value += rhs;
   ThrowIfOutOfRange();
   return *this;
}

SecureDouble& SecureDouble::operator+=(const SecureDouble& rhs)
{
   ClearFlags();
   m_value += rhs.GetValue();
   ThrowIfOutOfRange();
   return *this;
}

void SecureDouble::ClearFlags()
{
   feclearexcept(FE_OVERFLOW);
   feclearexcept(FE_UNDERFLOW);
}

void SecureDouble::ThrowIfOutOfRange()
{
   // [D4] Checking to see if type has overflown or underflow
   if (fetestexcept(FE_OVERFLOW))
   {
      throw SecurityException("Overflow in SecureDouble operation.");
   } 
   if (fetestexcept(FE_UNDERFLOW))
   {
      throw SecurityException("Underflow in SecureDouble operation.");
   }
}
