#ifndef INC_8085_CPP_MAIN_H
#define INC_8085_CPP_MAIN_H

#include "Essentials.h"

class Emulator8085 {
private:
    map<string, string> memory;
    vector<bool> flag;
    map<char, string> registers;
    string start;
    string pc;
    vector<string> programList;

public:
    Emulator8085();

    void init();
    void userInput();
    void userInputDebugger();
    void programFile(string name);
    void programFileDebugger(string name);
    void display();
};

#endif