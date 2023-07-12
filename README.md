# SPHINXKey

## Introduction

This project is dedicated to the world community as an Open-source Post-quantum blockchain layer 1 project, means anyone can join and contribute based on his/ her passion and skills. SPHINX is a blockchain protocol designed to provide secure and scalable solutions in the post-quantum era.

This repository contains code for the SPHINXKey project, which is a `Generating Key and Address` module for the SPHINX blockchain framework.

## Components

We are in the "Super Position" today to entering quantum-computers era, why we choosen hybrid scheme and why it must X25519 and Kyber768?

1. By combine X25519 and Kyber768 is to ensure it will safe against classical and computers era, however Kyber768 is new algorithm while X25519 is widely adopt and proven, so we called we area in the "Super Position".
2. X25519 and Kyber768 today already adopt by large tech community, thats as our role model abd made we are confident.

The combination of X25519 and Kyber768 in a hybrid key exchange is designed to harness the unique strengths of each algorithm, resulting in a more robust and versatile cryptographic solution.

X25519 is an elliptic curve Diffie-Hellman (ECDH) key exchange algorithm based on the Curve25519 curve. It offers several advantages, including efficient key generation, compact key sizes, and resilience against various common attacks. X25519 excels in terms of both performance and security, making it an ideal choice for key exchange operations.

On the other hand, Kyber768 is a post-quantum key encapsulation mechanism (KEM) that addresses the security challenges posed by quantum computers. It is based on the Learning With Errors (LWE) problem and provides strong resistance against attacks by quantum adversaries. Kyber768 offers a robust security guarantee in a post-quantum computing era when traditional cryptographic schemes may be vulnerable.

By combining X25519 and Kyber768 in a hybrid key exchange, you can leverage the efficiency and security benefits of X25519 while also incorporating the post-quantum resistance of Kyber768. This hybrid approach enables you to strike a balance between immediate performance needs and long-term security considerations. It is particularly advantageous in scenarios where both efficient key exchange and protection against future quantum threats are crucial.

### SPHINXKey Namespace

The `SPHINXKey` namespace provides functions for generating key pairs, calculating addresses, and printing key information. It relies on functionality from other included headers such as `Hybrid_key.hpp` and `Hash.hpp`.

#### Functions

##### `generate_hybrid_keypair()`

This function generates a hybrid key pair by calling the `generate_kyber768_key_pair()` and `generate_x25519_key_pair()` functions. It returns the generated hybrid key pair.

##### `generate_x25519_key_pair()`

This function generates an X25519 key pair using the `curve25519_generate_keypair` function. It returns a pair of arrays representing the private and public keys.

##### `generate_kyber768_key_pair()`

This function generates a Kyber768 private key using the `kyber768_kem::keygen` function. It returns the generated private key.

##### `merge_key_pair(const std::pair<unsigned char[32], unsigned char[32]>& x25519_key, const kyber768_kem::PrivateKey& kyber_key)`

This function merges the X25519 and Kyber768 key pairs into a hybrid key pair. It takes the X25519 key pair and Kyber768 private key as input parameters and returns the merged hybrid key pair.

##### `performX25519KeyExchange(unsigned char shared_key[32], const unsigned char private_key[32], const unsigned char public_key[32])`

This function performs the X25519 key exchange to obtain a shared key. It takes the private and public keys as input parameters and stores the shared key in the `shared_key` array.

##### `performHybridKeyExchange(unsigned char shared_key[32], const std::pair<unsigned char[32], unsigned char[32]>& x25519_key, const kyber768_kem::PrivateKey& kyber_key)`

This function performs the hybrid key exchange by combining X25519 and Kyber768. It calls the `performX25519KeyExchange` function and then performs the Kyber768 KEM encapsulation using the `kyber768_kem::encapsulate` function. It stores the shared key in the `shared_key` array.

##### `generate_and_perform_key_exchange()`

This function generates a hybrid key pair by calling `generate_hybrid_keypair` and then performs the hybrid key exchange using the generated key pair. It returns the hybrid key pair.

##### `generateAddress(const std::string& publicKey, const std::string& contractName)`

This function calculates the address for a smart contract based on a given public key and contract name. It takes the public key and contract name as input parameters and performs the following steps:

- Converts the public key string to an array of 32 unsigned char bytes.
- Calculates the SPHINX-256 hash of the public key using the `SPHINXHash::SPHINX_256` function.
- Generates a unique identifier for the smart contract by concatenating the contract name and the hash, separated by an underscore.
- Returns the contract identifier as the smart contract address.

##### `calculatePublicKey(const std::string& privateKey)`

This function calculates the public key from a given private key. It takes the private key as input and performs the following steps:

- Converts the private key string to an array of 32 unsigned char bytes.
- Calls the `generate_hybrid_keypair` function to obtain a hybrid key pair.
- Extracts the public key from the hybrid key pair and converts it to a string representation.
- Calculates the SPHINX-256 hash of the public key.
- Returns the calculated public key.

##### `printKeyPair(const SPHINXHybridKey::HybridKeypair& hybridKeyPair)`

This function prints the key pair information by extracting the public key from the merged key pair and calling the `SPHINXHybridKey::generateAddress` function to calculate the address. It then prints the merged public key, address, and the merged public key in the format (Kyber768-X25519).



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
