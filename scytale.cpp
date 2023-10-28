#include "scytale.h"
#include <string>

scytale::scytale()
{
}

std::string scytale::scytaleEncrypt(const std::string &text_to_cypher, int columns, char spaceChar)
{
    size_t text_length = text_to_cypher.length();
    size_t rows = (text_length + columns - 1) / columns;

    char scytale[rows][columns];
    int index = 0;

    std::string text_without_spaces = "";
    for (char c : text_to_cypher)
    {
        if (c != ' ')
        {
            text_without_spaces += c;
        }
    }

    for (int j = 0; j < columns; j++)
    {
        for (size_t i = 0; i < rows; i++)
        {
            if (index < text_without_spaces.length())
            {
                scytale[i][j] = text_without_spaces[index];
                index++;
            }
            else
            {
                scytale[i][j] = spaceChar;
            }
        }
    }

    std::string ciphered_text;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            ciphered_text += scytale[i][j];
        }
    }

    return ciphered_text;
}

std::string scytale::scytaleDecrypt(const std::string &ciphered_text, int columns, char spaceChar)
{
    int text_length = ciphered_text.length();
    int rows = (text_length + columns - 1) / columns;

    char scytale[rows][columns];
    int index = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scytale[i][j] = ciphered_text[index];
            index++;
        }
    }

    std::string text_to_cypher;
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (scytale[i][j] != spaceChar)
            {
                text_to_cypher += scytale[i][j];
            }
        }
    }

    return text_to_cypher;
}
