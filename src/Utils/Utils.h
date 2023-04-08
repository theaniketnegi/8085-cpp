//
// Created by anike on 07-04-2023.
//

#ifndef INC_8085_CPP_UTILS_H
#define INC_8085_CPP_UTILS_H

#include "../Essentials.h"

bool validateMemory(string&);
bool validateRegister(string&);
bool validateMemRegister(string&);
bool validateImmediateData(string&);
void setFlags(vector<bool>&, string);
string hexAdd(string, string, vector<bool>&);
string twosComplement(string& , vector<bool> );
string hexSub(string, string, vector<bool>&);
#endif //INC_8085_CPP_UTILS_H
