//
// Created by Tiffanie Lim on 11/6/24.
//

///reads words from a text file and stores them in a vector

#ifndef AUTOCORRECT_FILEREADER_H
#define AUTOCORRECT_FILEREADER_H
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

class FileReader {
private:
    std::vector<std::string> words;

public:
    FileReader(const std::string& filePath); //loads words from file
    const std::vector<std::string>& getWords() const; //returns loaded words
};

#endif //AUTOCORRECT_FILEREADER_H
