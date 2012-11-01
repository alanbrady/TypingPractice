#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include <list>
#include <string>
#include <time.h>
#include <stdlib.h>

class TextManager {

public:
    enum Mode { SequentialMode, RandomMode };

    TextManager(Mode inMode = SequentialMode);
    void setMode(Mode inMode);
    void addText(std::string newText);

    std::string getRemainder();
    std::list<std::string>& getAllText();
    std::string getNextLine();

private:
    Mode mode;
    std::list<std::string> text;
    std::string remainder;
    std::list<std::string>::iterator iter;

    std::string getSequentialLine();
    std::string getRandomLine();

    int lastNum;
};

#endif // TEXTMANAGER_H
