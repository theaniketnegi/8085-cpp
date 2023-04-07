#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include "Utils/Validate.h"

using namespace std;

class Emulator8085 {
    map <string, string> memory;
    vector<bool> flag; // CY _ P _ AC _ Z S
    map<char, string> registers; // A B C D E H L
    vector <string> sequence;
    string start;
    string pc;

public:
    Emulator8085() {
        flag = vector<bool>(8, false);
        registers = {{'A',"NULL"},
                     {'B',"NULL"},
                     {'C',"NULL"},
                     {'D',"NULL"},
                     {'E',"NULL"},
                     {'H',"NULL"},
                     {'L',"NULL"}};
        start = "";
        pc = "";
    }

    void input(){
        cout << "Enter a starting address: ";
        cin >> start;

        if(!validateMemory(start))
        {
            cout << "Invalid address." << endl;
            exit(1);
        }
        pc = start;

    }


    void setDummy() {
        flag[0] = true;
        flag[2] = true;
        memory["2050"] = "LDA 2070";
        memory["2051"] = "BRUH";
        registers['A'] = "43";
    }

    void display() {
        this->setDummy();
        cout << pc << endl;
        for(auto it: flag){
            cout << it << endl;
        }
        cout << endl << endl;
        for(auto it: memory){
            cout << it.first << " : " << it.second << endl;
        }
        cout << endl << endl;
        for(auto it: registers){
            cout << it.first << " : " << it.second << endl;
        }
    }
};

int main(int argc, char* args[]) {
    Emulator8085 emu;
    emu.input();
    cout << endl;
    if(argc == 1){
        cout << "Input the code" << endl; //User inputs code
    }
    else if(argc==2){
        if(!strcmpi(args[1],"--debugger")){
            cout << "Dummy debugger" << endl;
        }
        else{
            cout << "Executing code from " << args[1] << endl;
        }
    }
    else if(argc==3){
        if(strcmpi(args[2], "--debugger")){
            cout << "Invalid argument" << endl;
            exit(1);
        }
        else{
            cout << "Opening debugger with program from " << args[1] << endl;
        }
    }

    emu.display();
}