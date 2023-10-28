#include "caesar.h"

caesar::caesar()
{
}

std::string caesar::cypher_ceaser(int key, std::string text_to_cypher)
{
    char letter_to_move;
    for (int i = 0; text_to_cypher[i] != '\0'; ++i)
    {
        letter_to_move = text_to_cypher[i];
        if (letter_to_move >= 'a' && letter_to_move <= 'z')
        {
            letter_to_move = letter_to_move + key;
            if (letter_to_move > 'z')
            {
                letter_to_move = letter_to_move - 'z' + 'a' - 1;
            }
            text_to_cypher[i] = letter_to_move;
        }
        else if (letter_to_move >= 'A' && letter_to_move <= 'Z')
        {
            letter_to_move = letter_to_move + key;
            if (letter_to_move > 'Z')
            {
                letter_to_move = letter_to_move - 'Z' + 'A' - 1;
            }
            text_to_cypher[i] = letter_to_move;
        }
    }
    return text_to_cypher;
}

std::string caesar::decypher_caesar(int key, std::string text_to_decypher)
{
    char letter_to_move;
    for (int i = 0; text_to_decypher[i] != '\0'; ++i)
    {
        letter_to_move = text_to_decypher[i];
        if (letter_to_move >= 'a' && letter_to_move <= 'z')
        {
            letter_to_move = letter_to_move - key;
            if (letter_to_move < 'a')
            {
                letter_to_move = letter_to_move + 'z' - 'a' + 1;
            }
            text_to_decypher[i] = letter_to_move;
        }
        else if (letter_to_move >= 'A' && letter_to_move <= 'Z')
        {
            letter_to_move = letter_to_move - key;
            if (letter_to_move < 'A')
            {
                letter_to_move = letter_to_move + 'Z' - 'A' + 1;
            }
            text_to_decypher[i] = letter_to_move;
        }
    }
    return text_to_decypher;
}