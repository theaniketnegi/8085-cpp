#include <iostream>

using namespace std;

bool validateMemory(string& mem){
    if(mem.length()!=4)
        return false;
    for(char& c: mem){
        if(!((c>='A' && c<='F') || (c>='0' && c<='9') || (c>='A' && c<='F')))
            return false;
    }
    return true;
}

bool validateRegister(string& mem){
    if(mem=="A" || mem=="B" || mem=="C" || mem=="D" || mem == "E" || mem == "H" || mem=="L")
        return true;
    return false;
}

basic_string<char> validateMemRegister(string& mem){
    return mem=="M";
}