#include "textmanager.h"

TextManager::TextManager(Mode inMode)
    : mode(inMode) {
    this->iter = text.end();
    srand(time(NULL));
    lastNum = -1;
}

void TextManager::setMode(Mode inMode) {
    this->mode = inMode;
    this->iter = this->text.end();
}

void TextManager::addText(std::string newText) {
    unsigned int i = 0;

    newText = newText + " ";

    while ((i = newText.find("\n")) != std::string::npos) {
        newText.erase(i, 1);
    }

    if (remainder.length() > 0) {
        newText = remainder + newText;
    }

    i = 0;
    unsigned int k = 0;
    while((k = newText.find_first_of(".?", i)) != std::string::npos) {
        std::string sentence = newText.substr(i, k-i+1);
        this->text.push_back(sentence);
        if (k+1 < newText.length()) {
            i = k+1;
        } else {
            i = std::string::npos;
        }
    }
    if (i != std::string::npos) {
        this->remainder = newText.substr(i);
    } else {
        this->remainder = "";
    }
}

std::string TextManager::getRemainder() {
    return this->remainder;
}

std::list<std::string>& TextManager::getAllText() {
    return this->text;
}

std::string TextManager::getNextLine() {
    if (this->mode == SequentialMode) {
        return this->getSequentialLine();
    } else if (this->mode == RandomMode) {
        return this->getRandomLine();
    }
    return "";
}

std::string TextManager::getSequentialLine() {
    if (this->iter == text.end()) {
        this->iter == text.begin();
        this->iter++;
    }

    return *iter++;
}

std::string TextManager::getRandomLine() {
    int randNum = 0;
    do {
        randNum = (rand() % (text.size()-1))+1;
    } while(randNum == this->lastNum);
    lastNum = randNum;

    this->iter = text.begin();
    for (int i = 0; i < randNum; i++) {
       iter++;
    }
    return *iter;
}
