#pragma once

#include <stdexcept>

/// Custom exception class.
class SecurityException : public std::runtime_error
{
public:
   using runtime_error::runtime_error;
   const char* GetMessage() const { return what(); }
};
