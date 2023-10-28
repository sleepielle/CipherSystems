#ifndef CAESAR_H
#define CAESAR_H
#include <string>

class caesar
{

public:
    caesar();
    std::string cypher_ceaser(int key, std::string msg);
    std::string decypher_caesar(int key, std::string msg);
};

#endif
