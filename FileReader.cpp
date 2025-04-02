//
// Created by Tiffanie Lim on 11/6/24.
//

#include "FileReader.h"

FileReader::FileReader(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file)
        throw std::runtime_error("Unable to open file " + filePath);

    std::string word;
    while (file >> word)
        words.push_back(word);
}

const std::vector<std::string>& FileReader::getWords() const
{
    return words;
}
