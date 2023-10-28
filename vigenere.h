#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
class vigenere
{
public:
    vigenere(std::string key);
    std::string encryption(std::string text, std::string key);
    std::string decryption(std::string text, std::string key);
};
#endif
