#include "vigenere.h"
#include "caesar.h"
#include "scytale.h"

#include <limits>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    caesar c;
    scytale s;
    while (true)
    {
        string msg, word_key = "";
        int choice, key, diameter;
        char spaceChar;
        cout << "\n\nCRYTPOGRAPHY SIMULATOR\nEnter the message to cypher or decypher:\n";
        cin.ignore();
        getline(cin, msg);

        cout << "\nCEASAR CYPHER \n1. Encryption \n2. Decryption \n\nVIGENERE CYPHER\n3. Encryption\n4. Decryption\n\nSCYTALE CYPHER\n5. Encryption \n6. Decryption\n7. Exit\n";
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // CAESAR CYPHER
        if (choice == 1)
        {
            cout << "Enter key: ";
            cin >> key;
            string cypher = c.cypher_ceaser(key, msg);
            cout << "Caesar Encrypted message: " << cypher << "\n";
        }
        else if (choice == 2)
        {
            cout << "Enter key: ";
            cin >> key;
            string decypher = c.decypher_caesar(key, msg);
            cout << "Caesar Decrypted message: " << decypher << "\n";
        }
        // VIGENERE CYPHER
        else if (choice == 3)
        {
            cout << "Enter key: ";
            cin >> word_key;
            vigenere v(word_key);
            string encrypt = v.encryption(msg, word_key);
            cout << "Vigenere Encrypted Message: " << encrypt << endl;
        }
        else if (choice == 4)
        {
            cout << "Enter key: ";
            cin >> word_key;
            vigenere v(word_key);
            string decrypt = v.decryption(msg, word_key);
            cout << "Vigenere Decrypted Message: " << decrypt << endl;
        }

        // SCYTALE CYPHER
        else if (choice == 5)
        {

            std::cout << "Enter the number of columns: ";
            std::cin >> diameter;

            std::cout << "Enter the character for spaces: ";
            std::cin >> spaceChar;

            string scytale_encrypt = s.scytaleEncrypt(msg, diameter, spaceChar);
            cout << "Scytale Encrypted Message: " << scytale_encrypt << endl;
        }
        else if (choice == 6)
        {
            std::cout << "Enter the number of columns: ";
            std::cin >> diameter;

            std::cout << "Enter the character for spaces: ";
            std::cin >> spaceChar;

            string scytale_decrypt = s.scytaleDecrypt(msg, diameter, spaceChar);
            cout << "Scytale Decrypted Message: " << scytale_decrypt << endl;
        }

        else if (choice == 7)
        {
            cout << "Exiting the program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
    return 0;
}
