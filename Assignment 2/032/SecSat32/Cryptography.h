#pragma once

#include <cstdint>

class SecureString;

/// Responsible for any cryptographic operations, such has hashing and encryption.
class Cryptography
{
public:
   /// Hashes the given string using the given pepper. If no pepper is given, a random pepper is generated.
   static SecureString HashString(const SecureString& toHash, const int8_t pepper = GeneratePepper());

   /// Returns an encrypted of the given string, using the key provided.
   static SecureString  EncryptDecrypt(const std::string& string, const int8_t key);

   static const int8_t MinPepper = INT8_MIN;
   static const int8_t MaxPepper = INT8_MAX;

private:
   /// Returns a random int8_t between the values of MinPepper and MaxPepper.
   static int8_t GeneratePepper();
};
