#include <iostream>
#include <string.h>

using namespace std;

void encryption(char* cryptingKey, char* input, char* encryptedOutput)
{
    cout << "Insert the text you want to Encrypt with: ";
    cin >> cryptingKey;

    for (int input_index = 0; input_index < strlen(input); input_index++)
    {
        int crypting_key_index = input_index % strlen(cryptingKey);
        if(isalpha(input[input_index]))
        {
            if(isupper(input[input_index]))
            {
                if(isupper(cryptingKey[crypting_key_index]))
                {
                    encryptedOutput[input_index] = (input[input_index] - 65 + (cryptingKey[crypting_key_index] - 65) + 26) % 26 + 65;
                }
                else if(islower(cryptingKey[crypting_key_index]))
                {
                    cryptingKey[crypting_key_index] = (char)toupper(cryptingKey[crypting_key_index]);
                    encryptedOutput[input_index] = (input[input_index] - 65 + (cryptingKey[crypting_key_index] - 65) + 26) % 26 + 65;
                }
            }
            else if(islower(input[input_index]))
            {
                if(islower(cryptingKey[crypting_key_index]))
                {
                    encryptedOutput[input_index] = (input[input_index] - 97 + (cryptingKey[crypting_key_index] - 97) + 26) % 26 + 97;
                }
                else if(isupper(cryptingKey[crypting_key_index]))
                {
                    cryptingKey[crypting_key_index] = (char)tolower(cryptingKey[crypting_key_index]);
                    encryptedOutput[input_index] = (input[input_index] - 97 + (cryptingKey[crypting_key_index] - 97) + 26) % 26 + 97;
                }
            }
        }
    }

    cout << endl << "The encrypted string is: " << encryptedOutput << endl;
}

void decryption(char* cryptingKey, char* input, char* decryptedOutput)
{
    cout << "Insert the text you want to Decrypt with: ";
    cin >> cryptingKey;

    for (int input_index = 0; input_index < strlen(input); input_index++)
    {
        int crypting_key_index = input_index % strlen(cryptingKey);
        if(isalpha(input[input_index]))
        {
            if(isupper(input[input_index]))
            {
                if(isupper(cryptingKey[crypting_key_index]))
                {
                    decryptedOutput[input_index] = (input[input_index] - 65 - (cryptingKey[crypting_key_index] - 65) + 26) % 26 + 65;
                }
                else if(islower(cryptingKey[crypting_key_index]))
                {
                    cryptingKey[crypting_key_index] = (char)toupper(cryptingKey[crypting_key_index]);
                    decryptedOutput[input_index] = (input[input_index] - 65 - (cryptingKey[crypting_key_index] - 65) + 26) % 26 + 65;
                }
            }
            else if(islower(input[input_index]))
            {
                if(islower(cryptingKey[crypting_key_index]))
                {
                    decryptedOutput[input_index] = (input[input_index] - 97 - (cryptingKey[crypting_key_index] - 97) + 26) % 26 + 97;
                }
                else if(isupper(cryptingKey[crypting_key_index]))
                {
                    cryptingKey[crypting_key_index] = (char)tolower(cryptingKey[crypting_key_index]);
                    decryptedOutput[input_index] = (input[input_index] - 97 - (cryptingKey[crypting_key_index] - 97) + 26) % 26 + 97;
                }
            }
        }
    }

    cout << endl << "The decrypted string is: " << decryptedOutput << endl;
}

int main()
{
    char input[100] = {}, cryptingKey[100] = {}, encryptedOutput[100] = {}, decryptedOutput[100] = {};
    int choice;

    cout << "Enter your string: ";
    cin >> input;

    cout << endl << "=== Choose what you want to do ===" << endl;
    cout << "1. Encryption" << endl;
    cout << "2. Decryption" << endl;

    cout << endl << "Enter your choice: ";
    cin >> choice;
    
    switch(choice)
    {
        case 1:
            encryption(cryptingKey, input, encryptedOutput);
            break;
        case 2:
            decryption(cryptingKey, input, decryptedOutput);
            break;

        default:
            cout << endl << "Input error, choose a valid choice from above." << endl;
            break;
    }

    return 0;
}