//
// Created by Tiffanie Lim on 11/6/24.
//

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
    FileReader(const std::string& filePath);
    const std::vector<std::string>& getWords() const;
};

#endif //AUTOCORRECT_FILEREADER_H
