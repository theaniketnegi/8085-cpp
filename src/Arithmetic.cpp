#include <iostream>
#include <map>
#include <vector>
#include "Utils/Validate.h"
using namespace std;

void ADD(string reg, map<char, string>& registers, vector<bool>& flag, map<string, string>& memory){
    if(reg.length()==1){
        if(validateMemRegister(reg) || validateRegister(reg)){
            if(reg=="M"){
                string valueH = registers['H'];
                string valueM = registers['L'];
                string addressM = valueH+valueM;
                if(validateMemory(addressM)){

                }
            }
        }
    }
    else{
        cout << "Invalid register";
    }
}