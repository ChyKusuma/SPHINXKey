# SPHINXKey

## Introduction

This project is dedicated to the world community as an Open-source Post-quantum blockchain layer 1 project, means anyone can join and contribute based on his/ her passion and skills. SPHINX is a blockchain protocol designed to provide secure and scalable solutions in the post-quantum era.

This repository contains code for the SPHINXKey project, which is a `Generating Key and Address` module for the SPHINX blockchain framework.

## Components

### SPHINXKey Namespace

The `SPHINXKey` namespace provides functions for generating key pairs, calculating addresses, and printing key information. It relies on functionality from other included headers such as `Hybrid_key.hpp` and `Hash.hpp`.

### Functions

##### generate_hybrid_keypair()

This function generates a hybrid key pair by calling the `generate_kyber768_key_pair()` and `generate_x25519_key_pair()` functions. It returns the generated hybrid key pair.

##### generate_x25519_key_pair()

This function generates an X25519 key pair using the `curve25519_generate_keypair` function. It returns a pair of arrays representing the private and public keys.

##### generate_kyber768_key_pair()

This function generates a Kyber768 private key using the `kyber768_kem::keygen` function. It returns the generated private key.

##### merge_key_pair(const std::pair<unsigned char[32], unsigned char[32]>& x25519_key, const kyber768_kem::PrivateKey& kyber_key)

This function merges the X25519 and Kyber768 key pairs into a hybrid key pair. It takes the X25519 key pair and Kyber768 private key as input parameters and returns the merged hybrid key pair.

##### performX25519KeyExchange(unsigned char shared_key[32], const unsigned char private_key[32], const unsigned char public_key[32])

This function performs the X25519 key exchange to obtain a shared key. It takes the private and public keys as input parameters and stores the shared key in the `shared_key` array.

##### performHybridKeyExchange(unsigned char shared_key[32], const std::pair<unsigned char[32], unsigned char[32]>& x25519_key, const kyber768_kem::PrivateKey& kyber_key)

This function performs the hybrid key exchange by combining X25519 and Kyber768. It calls the `performX25519KeyExchange` function and then performs the Kyber768 KEM encapsulation using the `kyber768_kem::encapsulate` function. It stores the shared key in the `shared_key` array.

##### generate_and_perform_key_exchange()

This function generates a hybrid key pair by calling `generate_hybrid_keypair` and then performs the hybrid key exchange using the generated key pair. It returns the hybrid key pair.

##### generateAddress(const std::string& publicKey, const std::string& contractName)

This function calculates the address for a smart contract based on a given public key and contract name. It takes the public key and contract name as input parameters and performs the following steps:

- Converts the public key string to an array of 32 unsigned char bytes.
- Calculates the SPHINX-256 hash of the public key using the `SPHINXHash::SPHINX_256` function.
- Generates a unique identifier for the smart contract by concatenating the contract name and the hash, separated by an underscore.
- Returns the contract identifier as the smart contract address.

##### calculatePublicKey(const std::string& privateKey)

This function calculates the public key from a given private key. It takes the private key as input and performs the following steps:

- Converts the private key string to an array of 32 unsigned char bytes.
- Calls the `generate_hybrid_keypair` function to obtain a hybrid key pair.
- Extracts the public key from the hybrid key pair and converts it to a string representation.
- Calculates the SPHINX-256 hash of the public key.
- Returns the calculated public key.

##### printKeyPair(const SPHINXHybridKey::HybridKeypair& hybridKeyPair)

This function prints the key pair information by extracting the public key from the merged key pair and calling the `SPHINXHybridKey::generateAddress` function to calculate the address. It then prints the merged public key, address, and the merged public key in the format (Kyber768-X25519).


#### The interaction and collaboration between Key.cpp and [SPHINXHybridKey](https://github.com/ChyKusuma/SPHINXHybridKey) can be summarized as follows:

- In Key.cpp, the generate_hybrid_keypair() function is defined, which is responsible for generating a hybrid key pair. It internally calls functions from Hybrid_key.hpp to generate the Kyber768 key pair (generate_kyber768_key_pair()) and the X25519 key pair (generate_x25519_key_pair()). It also generates the PKE key pair and initializes the PRNG for key generation. Finally, it returns the hybrid key pair.

- The performX25519KeyExchange() function in Key.cpp is used to perform the X25519 key exchange. It takes the private and public keys as inputs and uses the performX25519KeyExchange() function from Hybrid_key.hpp to perform the actual key exchange.

- The performHybridKeyExchange() function in Key.cpp combines the X25519 and Kyber768 key pairs to perform a hybrid key exchange. It calls the performX25519KeyExchange() function and also uses the Kyber768 KEM (kyber768_kem::encapsulate) to encapsulate the shared key. The encapsulated key is stored in the shared_key parameter.

- The merge_key_pair() function in Key.cpp merges the X25519 and Kyber768 key pairs into a single hybrid key pair. It combines the X25519 public key and the Kyber768 private key, and generates the Kyber768 public key from the private key. The merged key pair is returned.

- The generate_and_perform_key_exchange() function in Key.cpp demonstrates the complete process of generating a hybrid key pair and performing the hybrid key exchange. It calls generate_hybrid_keypair() to generate the key pair and then calls performHybridKeyExchange() to perform the key exchange using the generated key pair.

- The generateAddress() function in Hybrid_key.hpp is used to generate a smart contract address based on a public key and contract name. It is called from the printKeyPair() function in Key.cpp to generate the address for a given public key.

- The calculatePublicKey() function in Key.cpp calculates the public key from a given private key. It internally uses functions from Hybrid_key.hpp to generate the hybrid key pair, merge the key pairs, and extract the X25519 public key.

The interaction between Key.cpp and Hybrid_key.hpp involves calling functions defined in Hybrid_key.hpp from Key.cpp to perform various operations related to hybrid key generation, key exchange, address generation, and public key calculation. Hybrid_key.hpp provides the necessary functions and data structures to support these operations, and Key.cpp utilizes them to implement the desired functionality.



### Note

Every code in the repository is a part of the SPHINX blockchain algorithm, which is currently in development and not fully integrated or extensively tested for functionality. The purpose of this repository is to provide a framework and algorithm for the digital signature scheme in the SPHINX blockchain project.

As the project progresses, further updates and enhancements will be made to ensure the code's stability and reliability. We encourage contributors to participate in improving and refining the SPHINXBlock algorithm by submitting pull requests and providing valuable insights.

We appreciate your understanding and look forward to collaborative efforts in shaping the future of the SPHINX blockchain project.


## Getting Started
To get started with the SPHINX blockchain project, follow the instructions below:

1. Clone the repository: `git clone https://github.com/ChyKusuma/SPHINXKey.git`
2. Install the necessary dependencies (List the dependencies or provide a link to the installation guide).
3. Explore the codebase to understand the project structure and components.
4. Run the project or make modifications as needed.


## Contributing
We welcome contributions from the developer community to enhance the SPHINX blockchain project. If you are interested in contributing, please follow the guidelines below:

1. Fork the repository on GitHub.
2. Create a new branch for your feature or bug fix: `git checkout -b feature/your-feature-name` or `git checkout -b bugfix/your-bug-fix`.
3. Make your modifications and ensure the code remains clean and readable.
4. Write tests to cover the changes you've made, if applicable.
5. Commit your changes: `git commit -m "Description of your changes"`.
6. Push the branch to your forked repository: `git push origin your-branch-name`.
7. Open a pull request against the main repository, describing your changes and the problem it solves.
8. Insert your information (i.e name, email) in the authors space.

## License
Specify the license under which the project is distributed (MIT License).

## Contact
If you have any questions, suggestions, or feedback regarding the SPHINX blockchain project, feel free to reach out to us at [sphinxfounders@gmail.com](mailto:sphinxfounders@gmail.com).
