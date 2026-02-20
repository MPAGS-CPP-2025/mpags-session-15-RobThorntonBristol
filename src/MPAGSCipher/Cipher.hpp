#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include <string>

/**
 * @brief Pure Abstract Base Class defining the interface for all cipher types.
 *
 * This class provides a common interface for encryption and decryption
 * algorithms. Derived classes must implement the applyCipher() function.
 */
class Cipher {
public:
    /// Default constructor
    Cipher() = default;

    /// Copy constructor
    Cipher(const Cipher&) = default;

    /// Move constructor
    Cipher(Cipher&&) = default;

    /// Copy assignment operator
    Cipher& operator=(const Cipher&) = default;

    /// Move assignment operator
    Cipher& operator=(Cipher&&) = default;

    /**
     * @brief Virtual destructor to allow safe polymorphic deletion.
     */
    virtual ~Cipher() = default;

    /**
     * @brief Apply the cipher to the supplied input text.
     *
     * @param input The text to encrypt or decrypt.
     * @param mode  The mode of operation (Encrypt or Decrypt).
     * @return The transformed (encrypted or decrypted) text.
     */
    virtual std::string applyCipher(const std::string& input,
                                    const CipherMode mode) const = 0;
};

#endif