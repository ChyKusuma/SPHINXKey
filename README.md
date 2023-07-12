# SPHINXKey

## Introduction

This project is dedicated to the world community as an Open-source Post-quantum blockchain layer 1 project, means anyone can join and contribute based on his/ her passion and skills. SPHINX is a blockchain protocol designed to provide secure and scalable solutions in the post-quantum era.

This repository contains code for the SPHINXSign project, which is a `Generating Key and Address` module for the SPHINX blockchain framework.

## Components

## SPHINXKey Namespace

The `SPHINXKey` namespace provides functions for generating key pairs, calculating addresses, and printing key information. It relies on functionality from other included headers such as `Hybrid_key.hpp`, `Hash.hpp`, and `Sign.hpp`.

### Functions

#### `generateKeyPair()`

This function generates a hybrid key pair by calling the `generateHybridKeypair()` function from `SPHINXHybridKey` namespace. It returns the generated key pair.

#### `generateAddress(const std::string& publicKey, const std::string& contractName)`

This function calculates the address for a smart contract based on a given public key and contract name. It takes the public key and contract name as input parameters and performs the following steps:

- Converts the public key string to an array of 32 unsigned char bytes.
- Calculates the SPHINX-256 hash of the public key using `SPHINXHash::SPHINX_256()` function.
- Generates a unique identifier for the smart contract by concatenating the contract name and the hash, separated by an underscore.
- Returns the contract identifier as the smart contract address.

#### `calculatePublicKey(const std::string& privateKey)`

This function calculates the public key from a given private key. It takes the private key as input and performs the following steps:

- Converts the private key string to an array of 32 unsigned char bytes.
- Calls the `generateKeyPair()` function to obtain a hybrid key pair.
- Converts the private key string to a `std::vector<uint8_t>` called `privateKeyVec`.
- Extracts the public key from the hybrid key pair and stores it in a `std::vector<uint8_t>` called `publicKey`.
- Calls the `SPHINXSign::verify_data()` function with the `privateKeyVec`, `publicKey.data()`, and `publicKeyBytes` as arguments.
- The resulting signature is stored but not used further.
- Converts the `publicKeyBytes` array to a string representation of the public key and returns it.

#### `printKeyPair()`

This function generates a hybrid key pair by calling the `generate_hybrid_keypair()` function from `SPHINXHybridKey` namespace.
It extracts the public key from the hybrid key pair and prints both the public key and the address by calling `SPHINXHash::SPHINX_256()` function.

**Note:** The provided code snippet doesn't show the complete implementation of the functions in the `SPHINXHybridKey`, `SPHINXHash`, and `SPHINXSign` namespaces. To fully understand the functionality, the implementation of those namespaces is required.


### Note

Every code in the repository is a part of the SPHINX blockchain algorithm, which is currently in development and not fully integrated or extensively tested for functionality. The purpose of this repository is to provide a framework and algorithm for the digital signature scheme in the SPHINX blockchain project.

As the project progresses, further updates and enhancements will be made to ensure the code's stability and reliability. We encourage contributors to participate in improving and refining the SPHINXBlock algorithm by submitting pull requests and providing valuable insights.

We appreciate your understanding and look forward to collaborative efforts in shaping the future of the SPHINX blockchain project.


## Getting Started
To get started with the SPHINX blockchain project, follow the instructions below:

1. Clone the repository: `git clone https://github.com/ChyKusuma/SPHINXSign.git`
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
