#include <sstream>
#include "Random.h"
#include "SecureString.h"
#include "SecureDouble.h"
#include "SecureInt32.h"

std::random_device Random::m_seedGenerator;
std::mt19937 Random::m_randomNumberGenerator(m_seedGenerator());

SecureDouble Random::GetRandom(const SecureDouble& min, const SecureDouble& max)
{
   std::uniform_real_distribution<double> distribution(min.GetValue(), max.GetValue());
   return SecureDouble(distribution(m_randomNumberGenerator));
}

SecureInt32 Random::GetRandom(const int32_t min, const int32_t max)
{
   std::uniform_int_distribution<int> distribution(min, max);
   return SecureInt32(distribution(m_randomNumberGenerator));
}

SecureString Random::GetRandom(const uint32_t length)
{
   std::stringstream stream;

   while (stream.str().length() < length)
   {
      stream << GetRandom(INT8_MIN, INT8_MAX).GetValue();
   }

   return SecureString(stream.str().length(), stream.str().c_str());
}
