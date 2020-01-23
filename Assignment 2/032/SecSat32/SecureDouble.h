#pragma once

/// Wraps a double. Throws if overflow or underflow is detected. 
class SecureDouble
{
public:
   SecureDouble();

   // Non-explicit converting constructor allows doubles to be passed to functions expecting SecureDoubles
   SecureDouble(const double initialValue); 

   double GetValue() const { return m_value; }
   SecureDouble& operator=(const double rhs);
   SecureDouble& operator+=(const double& rhs);
   SecureDouble& operator-=(const double& rhs);
   SecureDouble& operator=(const SecureDouble rhs);
   SecureDouble& operator+=(const SecureDouble& rhs);
   SecureDouble& operator-=(const SecureDouble& rhs);
   SecureDouble operator-() const;

private:
   /// Clears the error flags used to detect when underflow and overflow have occurred.
   static void ClearFlags();

   /// Throws if an overflow or underflow was detected.
   static void ThrowIfOutOfRange();

   double m_value;
};

inline SecureDouble operator-(SecureDouble lhs, const double& rhs)
{
   lhs -= rhs;
   return lhs;
}

inline SecureDouble operator+(SecureDouble lhs, const SecureDouble& rhs)
{
   lhs += rhs;
   return lhs;
}
