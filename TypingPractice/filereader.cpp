#include "filereader.h"
#include <fstream>

FileReader::FileReader(TextManager *inTextManager) {
    this->tm = inTextManager;
}

FileReader::FileReader() {
}

bool FileReader::readTextFile(std::string fileToRead) {
    std::ifstream inFile(fileToRead.c_str());
    bool success;

    if (inFile.is_open()) {
        std::string line;
        while (!inFile.eof()) {
            std::getline(inFile, line);
            if (line.length() > 0) {
                tm->addText(line);
            }
        }
        success = true;
    } else {
        success = false;
    }

    inFile.close();
    return success;
}

