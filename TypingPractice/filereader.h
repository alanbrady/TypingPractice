#ifndef FILEREADER_H
#define FILEREADER_H

#include "textmanager.h"
#include <string>

class FileReader
{
public:
    FileReader(TextManager* inTextManager);

    bool readTextFile(std::string fileToRead);
private:
    TextManager *tm;
    FileReader();
};

#endif // FILEREADER_H
