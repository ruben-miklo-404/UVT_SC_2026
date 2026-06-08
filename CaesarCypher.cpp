#include <iostream>
#include <string.h>
#include <fstream>

void encryption(int cipherKey, std::string input, std::string output, std::string inputFileName, std::string outputFileName, char* encryptedOutput)
{
    std::ifstream inputFile(inputFileName, std::ios::binary);
    if(inputFile.is_open())
    {
        std::string dataFromFile;

        while(inputFile >> dataFromFile)
        {
            input = input + dataFromFile + " ";
        }
    }
    else
    {
        std::cout << "Error: Could not open the input file." << std::endl;
        exit(1);
    }
    inputFile.close();

    int inputLength = input.length();
    encryptedOutput = new char[inputLength + 1];

    for (int input_index = 0; input_index <= inputLength; input_index++)
    {
        if(input[input_index] == 32)
        {
            encryptedOutput[input_index] = 32;
        }
        else
        {
            encryptedOutput[input_index] = (input[input_index] + cipherKey) % 256;
        }
    }
    
    std::ofstream outputFile(outputFileName, std::ios::binary);

    outputFile << encryptedOutput;

    outputFile.close();
}

void decryption(int cipherKey, std::string input, std::string output, std::string inputFileName, std::string outputFileName, char* decryptedOutput)
{
    std::ifstream inputFile(inputFileName, std::ios::binary);
    if(inputFile.is_open())
    {
        std::string dataFromFile;

        while(inputFile >> dataFromFile)
        {
            input = input + dataFromFile + " ";
        }
    }
    else
    {
        std::cout << "Error: Could not open the input file." << std::endl;
        exit(1);
    }
    inputFile.close();

    int inputLength = input.length();
    decryptedOutput = new char[inputLength + 1];

    for (int input_index = 0; input_index <= inputLength; input_index++)
    {
        if(input[input_index] == 32)
        {
            decryptedOutput[input_index] = 32;
        }
        else
        {
            decryptedOutput[input_index] = (input[input_index] - cipherKey + 256) % 256;
        }
    }

    std::ofstream outputFile(outputFileName, std::ios::binary);

    outputFile << decryptedOutput;

    outputFile.close();
}

int main(int argc, char** argv)
{
    std::string ciphering, input, output, inputFileName, outputFileName;
    char encryptedOutput[100000] = {}, decryptedOutput[100000] = {};
    int cipherKey;

    if(argc != 7)
    {
        std::cout << "Error: Enter the required number of arguments." << std::endl;
        std::cout << "Usage: ./main -e/-d -input <file> <key - integer number> -output <file>" << std::endl;
        exit(3);
    }
    
    for(int argument_index = 1; argument_index < argc; argument_index++)
    {
        std::string argument = argv[argument_index];

        if(argument == "-e" || argument == "-d")
        {
            ciphering = argument;
        }
        else if(argument == "-input" && argument_index + 1 < argc)
        {
            inputFileName = argv[++argument_index];
        }
        else if(argument == "-output" && argument_index + 1 < argc)
        {
            outputFileName = argv[++argument_index];
        }
        else if(isdigit(argument[0]) || (argument[0] == '-' && isdigit(argument[1])))
        {
            cipherKey = stoi(argument);
        }
        else
        {
            std::cout << "Error: Incorrect arguments given" << std::endl;
            std::cout << "Usage: ./main -e/-d -input <file> <key> -output <file>" << std::endl;
            exit(4);
        }
    }

    if(ciphering == "-e")
    {
        encryption(cipherKey, input, output, inputFileName, outputFileName, encryptedOutput);
    }
    else if(ciphering == "-d")
    {
        decryption(cipherKey, input, output, inputFileName, outputFileName, decryptedOutput);
    }

    return 0;
}