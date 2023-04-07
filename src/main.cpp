#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

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

    void setDummy() {
        flag[0] = true;
        flag[2] = true;
        memory["2050"] = "LDA 2070";
        memory["2051"] = "BRUH";
        registers['A'] = "43";
    }

    void display() {
        this->setDummy();
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

int main() {
    Emulator8085 emu;
    emu.display();
}