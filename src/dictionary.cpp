#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"

Dictionary::Dictionary(string filename)
{
    std::ifstream file;
    file.open(filename);
    if (!file.is_open())
        throw std::invalid_argument("");
    else
    {
        std::string word;
        while (getline(file, word))
        {
            insert(word);
        }
    }
    file.close();
}
