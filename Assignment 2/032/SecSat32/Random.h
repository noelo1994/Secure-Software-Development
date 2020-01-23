#pragma once

#include <random>

class SecureDouble;
class SecureString;
class SecureInt32;

class Random
{
public:
   
   /// Returns a random number between the minimum and maximum given.
   static SecureDouble GetRandom(const SecureDouble& min, const SecureDouble& max);
   static SecureInt32 Random::GetRandom(const int32_t min, const int32_t max);

   /// Returns a random string of the length requested.
   static SecureString GetRandom(const uint32_t length);

private:
   static std::random_device m_seedGenerator;
   static std::mt19937 m_randomNumberGenerator;
};
