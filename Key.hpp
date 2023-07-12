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
#include "Sign.hpp"

namespace SPHINXKey {

    HybridKeypair generateKeyPair();

    std::string generateAddress(const std::string& publicKey, const std::string& contractName);

    std::string calculatePublicKey(const std::string& privateKey);

    void printKeyPair();

} // namespace SPHINXKey

#endif // SPHINX_KEY_HPP