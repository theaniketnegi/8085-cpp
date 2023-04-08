#include "Essentials.h"
#include "Arithmetic.h"
#include "Utils/Utils.h"

class Emulator8085 {
    map<string, string> memory;
    vector<bool> flag; // CY _ P _ AC _ Z S
    map<char, string> registers; // A B C D E H L
    vector<string> sequence;
    string start;
    string pc;
public:


    Emulator8085() {
        flag = vector<bool>(8, false);
        registers = {{'A', "NULL"},
                     {'B', "NULL"},
                     {'C', "NULL"},
                     {'D', "NULL"},
                     {'E', "NULL"},
                     {'H', "NULL"},
                     {'L', "NULL"}};
        start = "";
        pc = "";
    }

    void input() {
        cout << "Enter a starting address: ";
        cin >> start;

        if (!validateMemory(start)) {
            cout << "Invalid address." << endl;
            exit(1);
        }
        pc = start;

    }

    void dummyProcess() {
//        ADD INSTRUCTION CHECK - DONE
//        registers['A']="FF";
//        registers['D']="34";
//
//        ADD("D", registers, flag, memory);
//
//        memory["2050"]="34";
//        registers['A'] = "FF";
//        registers['H'] = "20";
//        registers['L'] = "50";
//        ADD("M", registers, flag, memory);


//        ADI INSTRUCTION CHECK
//        registers['A'] = "FF";
//        ADI("0F", registers, flag);

            registers['A'] = "00";
            registers['D'] = "FF";
            //0000 0011
            SUB("D", registers, flag, memory);
            ADI("00", registers, flag);
            ADD("D", registers, flag, memory);
            SUI("FF", registers, flag);

            registers['H'] = "20";
            registers['L'] = "50";
            memory["2050"] = "7F";
            INR("M", registers, flag, memory);
            registers['C'] = "0B";
            DCR("C", registers, flag, memory);

    }

    void display() {
        dummyProcess();
        cout << pc << endl;
        vector<string> flags = {"CY", "_", "P", "_", "AC", "_", "Z", "S"};

        cout << "FLAGS: " << endl;
        for (int i = 0; i < flag.size(); i++) {
            cout << flags[i] << " : ";
            cout << flag[i] << endl;
        }
        cout << endl;

        cout << "MEMORY: " << endl;
        for (auto it: memory) {
            cout << it.first << " : " << it.second << endl;
        }
        cout << endl << endl;

        cout << "REGISTERS: " << endl;
        for (auto it: registers) {
            cout << it.first << " : " << it.second << endl;
        }
    }
};

int main(int argc, char *args[]) {
    Emulator8085 emu;
    emu.input();

//    string result;
//    result = hexAdd("FF", "34", emu.flag);
//    cout << result;

    cout << endl;
    if (argc == 1) {
        cout << "Input the code" << endl; //User inputs code
    } else if (argc == 2) {
        if (!strcmpi(args[1], "--debugger")) {
            cout << "Dummy debugger" << endl;
        } else {
            cout << "Executing code from " << args[1] << endl;
        }
    } else if (argc == 3) {
        if (strcmpi(args[2], "--debugger")) {
            cout << "Invalid argument" << endl;
            exit(1);
        } else {
            cout << "Opening debugger with program from " << args[1] << endl;
        }
    }

    emu.display();
}