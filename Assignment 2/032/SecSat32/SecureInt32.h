#pragma once

#include <cstdint>

/// Wraps a int32_t. Throws if overflow or underflow is detected.
class SecureInt32
{
public:
   SecureInt32();
   explicit SecureInt32(const int32_t value);
   int32_t GetValue() const { return m_value; }

   SecureInt32& operator=(const int32_t rhs);
   SecureInt32& operator++();
   SecureInt32& operator+=(const rsize_t rhs);

private:
   int32_t m_value;
};

inline SecureInt32 operator+(SecureInt32 lhs, const rsize_t& rhs)
{
   lhs += rhs;
   return lhs;
}

