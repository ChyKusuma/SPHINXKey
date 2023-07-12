/*
 *  Copyright (c) (2023) SPHINX_ORG
 *  Authors:
 *    - (C kusuma) <thekoesoemo@gmail.com>
 *      GitHub: (https://github.com/chykusuma)
 *  Contributors:
 *    - (Contributor 1) <email1@example.com>
 *      Github: (https://github.com/yourgit)
 *    - (Contributor 2) <email2@example.com>
 *      Github: (https://github.com/yourgit)
 */



/////////////////////////////////////////////////////////////////////////////////////////////////////////
// The code is enclosed in the SPHINXHybridKey namespace.

  // The generate_hybrid_keypair function is responsible for generating a hybrid keypair. It initializes an instance of HybridKeypair and then generates the Kyber768 key pair, Kyber768 public key, and X25519 key pair. Finally, it returns the generated hybrid keypair.

  // The generate_x25519_key_pair function generates an X25519 key pair using the curve25519_generate_keypair function. It returns a pair of unsigned char arrays representing the public and private keys.

  // The generate_kyber768_key_pair function generates a Kyber768 private key using the keygen function. It returns the generated private key.

  // The merge_key_pair function merges the X25519 and Kyber768 key pairs into a hybrid keypair. It takes the X25519 key pair and Kyber768 private key as input and assigns them to the HybridKeypair structure.

  // The performX25519KeyExchange function performs the X25519 key exchange using the curve25519_generate_shared_secret function. It takes the private and public keys as input and generates a shared key.

  // The performHybridKeyExchange function performs the hybrid key exchange by combining X25519 and Kyber768. It first performs the X25519 key exchange using the shared key, private key, and public key. Then it encapsulates the shared key using the Kyber768 KEM encapsulation.

  // The generate_and_perform_key_exchange function generates a hybrid keypair and performs the hybrid key exchange using the generated keypair.

  // The generateAddress function generates a smart contract address based on the public key and contract name. It calculates the SPHINX-256 hash of the public key and appends it to the contract name to create a unique identifier for the smart contract.

  // The calculatePublicKey function calculates the public key from the private key. It generates a hybrid keypair, merges the key pairs, and extracts the X25519 public key. Then it calculates the SPHINX-256 hash of the X25519 public key and returns it.

  // The printKeyPair function prints the key pair information. It extracts the Kyber768 and X25519 public keys from the merged keypair and prints them along with the smart contract address generated using the generateAddress function.
/////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <string>
#include "Hybrid_key.hpp"
#include "Hash.hpp"


namespace SPHINXKey {

    // Function to generate the hybrid keypair
    HybridKeypair generate_hybrid_keypair() {
        HybridKeypair hybrid_keypair;

        // Generate the Kyber768 key pair
        hybrid_keypair.merged_key.kyber_private_key = generate_kyber768_key_pair();

        // Generate the Kyber768 public key from the private key
        hybrid_keypair.merged_key.kyber_public_key = kyber768_kem::keygen(hybrid_keypair.merged_key.kyber_private_key);

        // Generate the X25519 key pair
        hybrid_keypair.x25519_key = generate_x25519_key_pair();

        return hybrid_keypair;
    }

    // Function to generate the X25519 key pair
    std::pair<unsigned char[32], unsigned char[32]> generate_x25519_key_pair() {
        std::pair<unsigned char[32], unsigned char[32]> x25519_key;

        // Generate the X25519 key pair using curve25519_generate_keypair function
        curve25519_generate_keypair(x25519_key.first, x25519_key.second);
        
        return x25519_key;
    }

    // Function to generate the Kyber768 key pair
    kyber768_kem::PrivateKey generate_kyber768_key_pair() {
        kyber768_kem::PrivateKey private_key;

        // Generate the Kyber768 private key using keygen function
        kyber768_kem::keygen(private_key);
        
        return private_key;
    }

    // Function to merge the X25519 and Kyber768 key pairs
    HybridKeypair merge_key_pair(const std::pair<unsigned char[32], unsigned char[32]>& x25519_key,
                                const kyber768_kem::PrivateKey& kyber_key) {
        HybridKeypair hybrid_keypair;

        // Assign the X25519 key pair to hybrid_keypair
        hybrid_keypair.x25519_key = x25519_key;

        // Assign the Kyber768 private key to hybrid_keypair
        hybrid_keypair.merged_key.kyber_private_key = kyber_key;

        // Generate the Kyber768 public key from the Kyber768 private key
        hybrid_keypair.merged_key.kyber_public_key = kyber768_kem::keygen(hybrid_keypair.merged_key.kyber_private_key);

        return hybrid_keypair;
    }

    // Function to perform the X25519 key exchange
    void performX25519KeyExchange(unsigned char shared_key[32], const unsigned char private_key[32], const unsigned char public_key[32]) {
        // Perform the X25519 key exchange to obtain the shared key using curve25519_generate_shared_secret function
        curve25519_generate_shared_secret(shared_key, private_key, public_key);
    }

    // Function to perform the hybrid key exchange combining X25519 and Kyber768
    void performHybridKeyExchange(unsigned char shared_key[32], const std::pair<unsigned char[32], unsigned char[32]>& x25519_key,
                                 const kyber768_kem::PrivateKey& kyber_key) {
        // Perform the X25519 key exchange
        unsigned char x25519_shared_key[32];
        performX25519KeyExchange(x25519_shared_key, x25519_key.first, kyber_key.data());

        // Perform the Kyber768 KEM encapsulation using kyber768_kem::encapsulate function
        kyber768_kem::PublicKey kyber_public_key = kyber768_kem::keygen(kyber_key);
        kyber768_kem::encapsulate(shared_key, x25519_key.second, kyber_public_key.data());
    }

    // Function to generate the hybrid keypair and perform the key exchange
    HybridKeypair generate_and_perform_key_exchange() {
        HybridKeypair hybrid_keypair = generate_hybrid_keypair();

        // Perform the hybrid key exchange using the generated key pair
        performHybridKeyExchange(hybrid_keypair.merged_key.shared_key, hybrid_keypair.x25519_key, hybrid_keypair.merged_key.kyber_private_key);

        return hybrid_keypair;
    }

    // Function to generate the smart contract address based on the public key and contract name
    std::string generateAddress(const std::string& publicKey, const std::string& contractName) {
        // Calculate the SPHINX-256 hash of the public key using SPHINXHash::SPHINX_256 function
        std::string hash = SPHINXHash::SPHINX_256(publicKey);

        // Generate a unique identifier for the smart contract based on the contract name and public key hash
        std::string contractIdentifier = contractName + "_" + hash;

        // Use the contract identifier as the smart contract address
        std::string address = contractIdentifier;

        return address;
    }

    // Function to calculate the public key from the private key
    std::string calculatePublicKey(const std::string& privateKey) {
        // Convert the private key to bytes
        std::vector<uint8_t> privateKeyBytes(privateKey.begin(), privateKey.end());

        // Generate the hybrid key pair
        HybridKeypair hybridKeyPair;
        hybridKeyPair.x25519_key = generate_x25519_key_pair();
        hybridKeyPair.merged_key.kyber_private_key = generate_kyber768_key_pair();
        hybridKeyPair.merged_key.kyber_public_key = kyber768_kem::keygen(hybridKeyPair.merged_key.kyber_private_key);

        // Merge the X25519 and Kyber768 key pairs
        hybridKeyPair.merged_key = merge_key_pair(hybridKeyPair.x25519_key, hybridKeyPair.merged_key.kyber_private_key);

        // Get the X25519 public key from the hybrid key pair
        std::string x25519PublicKey(reinterpret_cast<const char*>(hybridKeyPair.x25519_key.first), 32);

        // Calculate the SPHINX-256 hash of the X25519 public key
        std::string calculatedPublicKey = SPHINXHash::SPHINX_256(x25519PublicKey);

        return calculatedPublicKey;
    }

    // Function to print the key pair information
    void printKeyPair(const SPHINXHybridKey::HybridKeypair& hybridKeyPair) {
        // Extract the public key from the merged key pair
        std::string mergedPublicKey(reinterpret_cast<const char*>(hybridKeyPair.merged_key.kyber_public_key.data()), kyber768_kem::public_key_length);

        // Print the merged public key and address
        std::cout << "Merged Public key: " << mergedPublicKey << std::endl;
        std::cout << "Address: " << SPHINXHybridKey::generateAddress(mergedPublicKey, "MyContract") << std::endl;

        // Extract the Kyber768 public key from the merged key pair
        std::string kyberPublicKey(reinterpret_cast<const char*>(hybridKeyPair.merged_key.kyber_public_key.k.data()), kyber768_kem::public_key_length);

        // Extract the X25519 public key from the merged key pair
        std::string x25519PublicKey(reinterpret_cast<const char*>(hybridKeyPair.x25519_key.first), 32);

        // Print the merged public key (Kyber768-X25519)
        std::cout << "Merged Public key (Kyber768-X25519): " << kyberPublicKey + x25519PublicKey << std::endl;
    }
} // namespace SPHINXKey
