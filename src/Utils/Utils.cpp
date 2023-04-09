#include <bitset>
#include "../Essentials.h"

int to_int(char &num) {
    map<char, int> mp ={
            {'0', 0},
            {'1', 1},
            {'2', 2},
            {'3', 3},
            {'4', 4},
            {'5', 5},
            {'6', 6},
            {'7', 7},
            {'8', 8},
            {'9', 9},
            {'A', 10},
            {'B', 11},
            {'C', 12},
            {'D', 13},
            {'E', 14},
            {'F', 15}
    };
    return mp[num];
}

char to_char(int& num){
    map<int, char> mp ={
            {0, '0'},
            {1, '1'},
            {2, '2'},
            {3, '3'},
            {4, '4'},
            {5, '5'},
            {6, '6'},
            {7, '7'},
            {8, '8'},
            {9, '9'},
            {10, 'A'},
            {11, 'B'},
            {12, 'C'},
            {13, 'D'},
            {14, 'E'},
            {15, 'F'}
    };

    return mp[num];
}

bool validateMemory(string &mem) {
    if (mem.length() != 4)
        return false;
    for (char &c: mem) {
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')))
            return false;
    }
    return true;
}

bool validateRegister(string &mem) {
    if (mem == "A" || mem == "B" || mem == "C" || mem == "D" || mem == "E" || mem == "H" || mem == "L")
        return true;
    return false;
}

bool validRegisterPair(string &mem){
    if(mem=="B" || mem=="D" || mem=="H")
        return true;
    return true;
}


bool validateMemRegister(string &mem) {
    return mem == "M";
}

bool validateImmediateData(string& data){
    for(char& c: data){
        if(!((c>='A' && c<='F') || (c>='0' && c<='9')))
            return false;
    }
    return true;
}

void setFlags(vector<bool>& flag, string result){
    flag[6] = (result=="00");
    int hex = stoi(result, nullptr, 16);
    bitset<8> bits(hex);

    if((bits.count()%2)==0)
        flag[2] = true;
    else
        flag[2] = false;

    flag[7] = bits[7];
}

string hexAdd(string regA, string regB, vector<bool>& flag) {
    string result = "  ";
    int carry = 0;
    for (int i = 1; i >= 0; i--) {
        int sum = to_int(regA[i]) + to_int(regB[i]) + carry;
        if(sum>=16){
            carry=1;
            sum = sum - 16;
        }
        else{
            carry=0;
        }

        result[i] = to_char(sum);
        if(i==1)
            flag[4]= carry == 1; //AC
    }
    flag[0]= carry == 1; // CY
    setFlags(flag, result);
    return result;
}

string hexAdd16(string regA, string regB, vector<bool>& flag, bool isDAD) {
    string result = "    ";
    int carry = 0;
    for (int i = 3; i >= 0; i--) {
        int sum = to_int(regA[i]) + to_int(regB[i]) + carry;
        if(sum>=16){
            carry=1;
            sum = sum - 16;
        }
        else{
            carry=0;
        }
        flag[0] = carry==1 && isDAD;
        result[i] = to_char(sum);
    }

    return result;
}

string twosComplement(string& data, vector<bool> flag){
    string result = "  ";
    string comp = "FF";
    for(int i=data.length()-1; i>=0; i--) {
        int diff = to_int(comp[i]) - to_int(data[i]);
        result[i] = to_char(diff);
    }
    result = hexAdd(result, "01", flag);
    return result;
}

string twosComplement16(string data, vector<bool> flag){
    string result = "    ";
    string comp = "FFFF";
    for(int i=data.length()-1; i>=0; i--) {
        int diff = to_int(comp[i]) - to_int(data[i]);
        result[i] = to_char(diff);
    }
    result = hexAdd16(result, "0001", flag, false);
    return result;
}

string hexSub(string regA, string regB, vector<bool>& flag){
    string result = hexAdd(regA, twosComplement(regB, flag), flag);
    flag[4]=false;
    flag[0]=false;

    for(int i=regA.length()-1; i>=0; i--){
        int digitA = to_int(regA[i]);
        int digitB = to_int(regB[i]);
        if(digitA < digitB){
            if(i==1)
                flag[4] = true;
            if(i==0)
                flag[0] = true;
        }
    }
    return result;
}
