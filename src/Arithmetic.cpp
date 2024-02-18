#include "Headers/Essentials.h"
#include "Utils/Utils.h"

void ADD(string reg, map<char, string> &registers, vector<bool> &flag, map<string, string> &memory)
{
	if (reg.length() == 1)
	{
		if (validateMemRegister(reg) || validateRegister(reg))
		{
			if (reg == "M")
			{
				string valueH = registers['H'];
				string valueM = registers['L'];
				string addressM = valueH + valueM;
				if (validateMemory(addressM))
				{
					registers['A'] = hexAdd(registers['A'], memory[addressM], flag);
				}
				else
				{
					throw invalid_argument("Invalid address");
				}
			}
			else
			{
				registers['A'] = hexAdd(registers['A'], registers[reg[0]], flag);
			}
		}
		else
		{
			throw invalid_argument("Invalid register");
		}
	}
	else
	{
		throw invalid_argument("Invalid register");
	}
}

void ADI(string data, map<char, string> &registers, vector<bool> &flag)
{
	registers['A'] = hexAdd(registers['A'], data, flag);
}

void SUB(string reg, map<char, string> &registers, vector<bool> &flag, map<string, string> &memory)
{
	if (reg.length() == 1)
	{
		if (validateMemRegister(reg) || validateRegister(reg))
		{
			if (reg == "M")
			{
				string valueH = registers['H'];
				string valueM = registers['L'];
				string addressM = valueH + valueM;
				if (validateMemory(addressM))
				{
					registers['A'] = hexSub(registers['A'], memory[addressM], flag);
				}
				else
				{
					throw invalid_argument("Invalid address");
				}
			}
			else
			{
				registers['A'] = hexSub(registers['A'], registers[reg[0]], flag);
			}
		}
		else
		{
			throw invalid_argument("Invalid register");
		}
	}
	else
	{
		throw invalid_argument("Invalid register");
	}
}

void SUI(string data, map<char, string> &registers, vector<bool> &flag)
{
	registers['A'] = hexSub(registers['A'], data, flag);
}

void INR(string reg, map<char, string> &registers, vector<bool> &flag, map<string, string> &memory)
{
	if (reg.length() == 1)
	{
		if (validateMemRegister(reg) || validateRegister(reg))
		{
			if (reg == "M")
			{
				string valueH = registers['H'];
				string valueM = registers['L'];
				string addressM = valueH + valueM;
				if (validateMemory(addressM))
				{
					memory[addressM] = hexAdd(memory[addressM], "01", flag);
					flag[0] = false;
					flag[4] = false;
				}
				else
				{
					throw invalid_argument("Invalid address");
				}
			}
			else
			{
				registers[reg[0]] = hexAdd(registers[reg[0]], "01", flag);
				flag[0] = false;
				flag[4] = false;
			}
		}
		else
		{
			throw invalid_argument("Invalid register");
		}
	}
	else
	{
		throw invalid_argument("Invalid register");
	}
}

void INX(string reg, map<char, string> &registers, vector<bool> &flag)
{
	if (reg.length() == 1)
	{
		if (validRegisterPair(reg))
		{
			string valueA = registers[reg[0]];
			char regPair;
			if (reg == "B")
				regPair = 'C';
			else if (reg == "D")
				regPair = 'E';
			else
				regPair = 'L';
			string valueB = registers[regPair];
			string result = valueA + valueB;
			result = hexAdd16(result, "0001", flag, false);

			registers[reg[0]] = string(1, result[0]) + string(1, result[1]);
			registers[regPair] = string(1, result[2]) + string(1, result[3]);
		}
		else
		{
			throw invalid_argument("Invalid register pair");
		}
	}
	else
	{
		throw invalid_argument("Invalid register pair");
	}
}

void DCR(string reg, map<char, string> &registers, vector<bool> &flag, map<string, string> &memory)
{
	if (reg.length() == 1)
	{
		if (validateMemRegister(reg) || validateRegister(reg))
		{
			if (reg == "M")
			{
				string valueH = registers['H'];
				string valueM = registers['L'];
				string addressM = valueH + valueM;
				if (validateMemory(addressM))
				{
					memory[addressM] = hexSub(memory[addressM], "01", flag);
					flag[0] = false;
					flag[4] = false;
				}
				else
				{
					throw invalid_argument("Invalid address");
				}
			}
			else
			{
				registers[reg[0]] = hexSub(registers[reg[0]], "01", flag);
				flag[0] = false;
				flag[4] = false;
			}
		}
		else
		{
			throw invalid_argument("Invalid register");
		}
	}
	else
	{
		throw invalid_argument("Invalid register");
	}
}

void DCX(string reg, map<char, string> &registers, vector<bool> &flag)
{
	if (reg.length() == 1)
	{
		if (validRegisterPair(reg))
		{
			string valueA = registers[reg[0]];
			char regPair;
			if (reg == "B")
				regPair = 'C';
			else if (reg == "D")
				regPair = 'E';
			else
				regPair = 'L';
			string valueB = registers[regPair];
			string result = valueA + valueB;
			result = hexAdd16(result, twosComplement16("0001", flag), flag, false);

			registers[reg[0]] = string(1, result[0]) + string(1, result[1]);
			registers[regPair] = string(1, result[2]) + string(1, result[3]);
		}
		else
		{
			throw invalid_argument("Invalid register pair");
		}
	}
	else
	{
		throw invalid_argument("Invalid register");
	}
}

void DAD(string reg, map<char, string> &registers, vector<bool> &flag)
{
	if (reg.length() == 1)
	{
		if (validRegisterPair(reg))
		{
			string valueA = registers[reg[0]];
			char regPair;
			if (reg == "B")
				regPair = 'C';
			else if (reg == "D")
				regPair = 'E';
			else
				regPair = 'L';
			string valueB = registers[regPair];
			string result = valueA + valueB;

			string HL = registers['H'] + registers['L'];
			result = hexAdd16(HL, result, flag, true);

			registers['H'] = string(1, result[0]) + string(1, result[1]);
			registers['L'] = string(1, result[2]) + string(1, result[3]);
		}
		else
		{
			throw invalid_argument("Invalid register pair");
		}
	}
	else
	{
		throw invalid_argument("Invalid register");
	}
}
