#include <sstream>
#include "Cryptography.h"
#include "Random.h"
#include "SecureString.h"
#include "SecureInt32.h"

SecureString Cryptography::HashString(const SecureString& toHash, const int8_t pepper)
{
   SecureString stringPlusPepper = toHash + pepper;
   std::stringstream stream;
   SecureInt32 index(0);
   int8_t stringPlusPeppercharacter;

   // Because a SecureString is being used, we know that the string will be null terminated
   while ((stringPlusPeppercharacter = stringPlusPepper.GetValue()[index.GetValue()]) != 0)
   {
      // The primitive int is used here because it allows the the hash to be converted to hex on the next line.
      // The C++ standard guarantees that an int must be at least 16 bits in length, so we know that the int will
      // be large enough to hold the value of a int8_t.
      const int modifiedcharacter = stringPlusPeppercharacter ^ 'P'; 
      
      stream << std::hex << modifiedcharacter;
      ++index;
   }

   return SecureString(stream.str().length(), stream.str().c_str());
}

SecureString Cryptography::EncryptDecrypt(const std::string& string, const int8_t key)
{
   std::stringstream stream;

   for (const int8_t character : string)
   {
      stream << (character ^ key);
   }

   return SecureString(string.length(), stream.str().c_str());
}

int8_t Cryptography::GeneratePepper()
{
   SecureInt32 pepper(Random::GetRandom(MinPepper, MaxPepper));

   // [D19] Avoiding dangerous cast by performing checks first
   // Because the type of MinPepper and MaxPepper is int8_t, we know that the random number should be in the range of a int8_t.
   // However, because GetRandom returns an SecureInt, which internally uses a int32_t, it is best not to assume how GetRandom has
   // been implemented and check anyway before casting, to prevent loss of data when casting from a larger type to a smaller one. 
   // Note that this would not actually be a security concern, as we only need the pepper to be a random number.
   if ((pepper.GetValue() > MaxPepper) || (pepper.GetValue() < MinPepper))
   {
      throw SecurityException("Random pepper was not in the valid range for a pepper during pepper generation.");
   }

   // At this stage, we know that the cast is safe
   return static_cast<int8_t>(pepper.GetValue());
}
