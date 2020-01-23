#pragma once

#include <cstdint>

/// Wraps a uint32_t. Throws if overflow or underflow is detected.
class SecureUInt32
{
public:
   SecureUInt32();
   explicit SecureUInt32(const uint32_t value);
   uint32_t GetValue() const { return m_value; }

   SecureUInt32& operator=(const uint32_t rhs);
   SecureUInt32& operator++();
   SecureUInt32& operator+=(const rsize_t rhs);

private:
   uint32_t m_value;
};

inline SecureUInt32 operator+(SecureUInt32 lhs, const rsize_t& rhs)
{
   lhs += rhs;
   return lhs;
}