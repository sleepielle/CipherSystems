#ifndef SCYTALE_H
#define SCYTALE_H

#include <iostream>
#include <string>
#include <cmath>

class scytale
{
public:
    scytale();

    std::string scytaleEncrypt(const std::string &plaintext, int diameter, char spaceChar);
    std::string scytaleDecrypt(const std::string &ciphertext, int diameter, char spaceChar);
};

#endif