/*
 *  Copyright (c) (2023) SPHINX_ORG
 *  Authors:
 *    - (C kusuma) <thekoesoemo@gmail.com>
 *      GitHub: (https://github.com/cahyaksm)
 *  Contributors:
 *    - (Contributor 1) <email1@example.com>
 *      Github: (https://github.com/yourgit)
 *    - (Contributor 2) <email2@example.com>
 *      Github: (https://github.com/yourgit)
 */


#ifndef SPHINX_KEY_HPP
#define SPHINX_KEY_HPP

#include <iostream>
#include <string>
#include "Hybrid_key.hpp"
#include "Hash.hpp"

namespace SPHINXKey {

    // Structure to hold the merged keypair
    struct HybridKeypair {
        struct {
            // Kyber768 keypair
            kyber768_kem::PublicKey kyber_public_key;
            kyber768_kem::PrivateKey kyber_private_key;
        } merged_key;

        // X25519 keypair
        std::pair<unsigned char[32], unsigned char[32]> x25519_key;
    };

    // Function to generate the hybrid keypair
    HybridKeypair generate_hybrid_keypair();

    // Function to generate the X25519 key pair
    std::pair<unsigned char[32], unsigned char[32]> generate_x25519_key_pair(const std::vector<uint8_t>& privateKeyBytes);

    // Function to generate the Kyber768 key pair
    kyber768_kem::PrivateKey generate_kyber768_key_pair();

    // Function to merge the X25519 and Kyber768 key pairs
    HybridKeypair merge_key_pair(const std::pair<unsigned char[32], unsigned char[32]>& x25519_key,
                                const kyber768_kem::PrivateKey& kyber_key);

    // Function to perform the X25519 key exchange
    void performX25519KeyExchange(unsigned char shared_key[32], const unsigned char private_key[32], const unsigned char public_key[32]);

    // Function to perform the hybrid key exchange combining X25519 and Kyber768
    void performHybridKeyExchange(unsigned char shared_key[32], const std::pair<unsigned char[32], unsigned char[32]>& x25519_key,
                                 const kyber768_kem::PrivateKey& kyber_key);

    // Function to generate the hybrid keypair and perform the key exchange
    HybridKeypair generate_and_perform_key_exchange();

}  // namespace SPHINXKey

#endif // SPHINX_KEY_HPP
