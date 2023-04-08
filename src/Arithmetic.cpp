#include "Essentials.h"
#include "Utils/Utils.h"

void ADD(string reg, map<char, string>& registers, vector<bool>& flag, map<string, string>& memory){
    if(reg.length()==1){
        if(validateMemRegister(reg) || validateRegister(reg)){
            if(reg=="M"){
                string valueH = registers['H'];
                string valueM = registers['L'];
                string addressM = valueH+valueM;
                if(validateMemory(addressM)){
                    registers['A'] = hexAdd(registers['A'], memory[addressM], flag);
                }
                else{
                    cout << "Invalid address" << endl;
                    exit(0);
                }
            }
            else{
                registers['A'] = hexAdd(registers['A'], registers[reg[0]], flag);
            }
        }
        else{
            cout << "Invalid register" << endl;
            exit(0);
        }
    }
    else{
        cout << "Invalid register";
        exit(0);
    }
}

void ADI(string data, map<char, string>& registers, vector<bool>& flag){
    if(data.length()!=2 || !validateImmediateData(data)){
        cout << "Invalid value";
        exit(0);
    }
    else{
        registers['A'] = hexAdd(registers['A'], data, flag);
    }
}

void SUB(string reg, map<char, string>& registers, vector<bool>& flag, map<string, string>& memory){
    if(reg.length()==1){
        if(validateMemRegister(reg) || validateRegister(reg)){
            if(reg=="M"){
                string valueH = registers['H'];
                string valueM = registers['L'];
                string addressM = valueH+valueM;
                if(validateMemory(addressM)){
                    registers['A'] = hexSub(registers['A'], memory[addressM], flag);
                }
                else{
                    cout << "Invalid address" << endl;
                    exit(0);
                }
            }
            else{
                registers['A'] = hexSub(registers['A'], registers[reg[0]], flag);
            }
        }
        else{
            cout << "Invalid register" << endl;
            exit(0);
        }
    }
    else{
        cout << "Invalid register";
        exit(0);
    }
}

void SUI(string data, map<char, string>& registers, vector<bool>& flag){
    if(data.length()!=2 || !validateImmediateData(data)){
        cout << "Invalid value";
        exit(0);
    }
    else{
        registers['A'] = hexSub(registers['A'], data, flag);
    }
}

void INR(string reg, map<char, string>& registers, vector<bool>& flag, map<string, string>& memory){
    if(reg.length()==1){
        if(validateMemRegister(reg) || validateRegister(reg)){
            if(reg=="M"){
                string valueH = registers['H'];
                string valueM = registers['L'];
                string addressM = valueH+valueM;
                if(validateMemory(addressM)){
                    memory[addressM] = hexAdd(memory[addressM], "01", flag);
                }
                else{
                    cout << "Invalid address" << endl;
                    exit(0);
                }
            }
            else{
                registers[reg[0]] = hexAdd(registers[reg[0]], "01", flag);
            }
        }
        else{
            cout << "Invalid register" << endl;
            exit(0);
        }
    }
    else{
        cout << "Invalid register";
        exit(0);
    }
}

void DCR(string reg, map<char, string>& registers, vector<bool>& flag, map<string, string>& memory){
    if(reg.length()==1){
        if(validateMemRegister(reg) || validateRegister(reg)){
            if(reg=="M"){
                string valueH = registers['H'];
                string valueM = registers['L'];
                string addressM = valueH+valueM;
                if(validateMemory(addressM)){
                    memory[addressM] = hexSub(memory[addressM], "01", flag);
                }
                else{
                    cout << "Invalid address" << endl;
                    exit(0);
                }
            }
            else{
                registers[reg[0]] = hexSub(registers[reg[0]], "01", flag);
            }
        }
        else{
            cout << "Invalid register" << endl;
            exit(0);
        }
    }
    else{
        cout << "Invalid register";
        exit(0);
    }
}
