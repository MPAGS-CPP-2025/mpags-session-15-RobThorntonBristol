// src/Testing/testCiphers.cpp
#include "gtest/gtest.h"

#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"
#include "PlayfairCipher.hpp"
#include "Cipher.hpp"
#include "CipherMode.hpp"


bool testCipher(const Cipher& cipher,
                const CipherMode mode,
                const std::string& inputText,
                const std::string& expectedOutput)
{
    std::string result = cipher.applyCipher(inputText, mode);
    return result == expectedOutput;
}

// ==================== Caesar Cipher ====================

TEST(CaesarCipher, EncryptDecrypt)
{
    CaesarCipher caesar{3};

    EXPECT_TRUE(testCipher(caesar, CipherMode::Encrypt, "HELLO", "KHOOR"));
    EXPECT_TRUE(testCipher(caesar, CipherMode::Decrypt, "KHOOR", "HELLO"));
}

// ==================== Vigenère Cipher ====================

TEST(VigenereCipher, EncryptDecrypt)
{
    VigenereCipher vigenere{"KEY"};

    EXPECT_TRUE(testCipher(vigenere, CipherMode::Encrypt, "HELLO", "RIJVS"));
    EXPECT_TRUE(testCipher(vigenere, CipherMode::Decrypt, "RIJVS", "HELLO"));
}

// ==================== Playfair Cipher ====================

TEST(PlayfairCipher, EncryptDecrypt)
{
    PlayfairCipher playfair{"KEYWORD"};

    EXPECT_TRUE(testCipher(playfair, CipherMode::Encrypt, "HELLO", "GYIZSC"));
    EXPECT_TRUE(testCipher(playfair, CipherMode::Decrypt, "GYIZSC", "HELXLO"));
}