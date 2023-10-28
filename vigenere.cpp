#include "vigenere.h"

//
vigenere::vigenere(std::string key)
{
    for (int i = 0; i < key.size(); ++i)
    {
        if (key[i] >= 'A' && key[i] <= 'Z')
            key += key[i];
        else if (key[i] >= 'a' && key[i] <= 'z')
            key += key[i] + 'A' - 'a';
    }
}

std::string vigenere::encryption(std::string text, std::string key)
{
    std::string cyphered_text;
    for (int i = 0, j = 0; i < text.length(); ++i)
    {
        char letter_to_move = text[i];
        if (letter_to_move >= 'a' && letter_to_move <= 'z')
            letter_to_move += 'A' - 'a';
        else if (letter_to_move < 'A' || letter_to_move > 'Z')
            continue;
        cyphered_text += ((letter_to_move + key[j] - 2 * 'A') % 26) + 'A';
        j = (j + 1) % key.length();
    }
    return cyphered_text;
}

std::string vigenere::decryption(std::string text, std::string key)
{
    std::string decyphered_text;
    for (int i = 0, j = 0; i < text.length(); ++i)
    {
        char letter_to_move = text[i];
        if (letter_to_move >= 'a' && letter_to_move <= 'z')
            letter_to_move += 'A' - 'a';
        else if (letter_to_move < 'A' || letter_to_move > 'Z')
            continue;
        decyphered_text += ((letter_to_move - key[j] + 26) % 26) + 'A';
        j = (j + 1) % key.length();
    }
    return decyphered_text;
}
