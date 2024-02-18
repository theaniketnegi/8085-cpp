#include <gtest/gtest.h>
#include "../Headers/Arithmetic.h"

class ArithmeticTestFixture : public ::testing::Test
{
protected:
	map<string, string> memory;
	vector<bool> flag;
	map<char, string> registers;

	virtual void SetUp()
	{
		memory.clear();
		flag.assign(8, false);
		registers = {
			{'A', "NULL"},
			{'B', "NULL"},
			{'C', "NULL"},
			{'D', "NULL"},
			{'E', "NULL"},
			{'H', "NULL"},
			{'L', "NULL"}};
	}
};

TEST_F(ArithmeticTestFixture, Add_A_Register)
{
	registers['A'] = "03";
	registers['D'] = "04";
	ADD("D", registers, flag, memory);
	EXPECT_EQ(registers['A'], "07");
}

TEST_F(ArithmeticTestFixture, Add_a_Register_CY)
{
	registers['A'] = "FF";
	registers['D'] = "34";
	ADD("D", registers, flag, memory);
	EXPECT_EQ(registers['A'], "33");
	EXPECT_EQ(flag[0], true);
}

TEST_F(ArithmeticTestFixture, Add_a_Register_AC)
{
	registers['A'] = "08";
	registers['D'] = "09";
	ADD("D", registers, flag, memory);
	EXPECT_EQ(registers['A'], "11");
	EXPECT_EQ(flag[4], true);
}

TEST_F(ArithmeticTestFixture, Add_Memory)
{
	memory["2050"] = "04";
	registers['A'] = "03";
	registers['H'] = "20";
	registers['L'] = "50";
	ADD("M", registers, flag, memory);
	EXPECT_EQ(registers['A'], "07");
}
TEST_F(ArithmeticTestFixture, Add_Memory_CY)
{
	memory["2050"] = "34";
	registers['A'] = "FF";
	registers['H'] = "20";
	registers['L'] = "50";
	ADD("M", registers, flag, memory);
	EXPECT_EQ(registers['A'], "33");
	EXPECT_EQ(flag[0], true);
}

TEST_F(ArithmeticTestFixture, Add_Memory_AC)
{
	memory["2050"] = "09";
	registers['A'] = "08";
	registers['H'] = "20";
	registers['L'] = "50";
	ADD("M", registers, flag, memory);
	EXPECT_EQ(registers['A'], "11");
	EXPECT_EQ(flag[4], true);
}

TEST_F(ArithmeticTestFixture, Add_Validation)
{
	EXPECT_THROW(ADD("F", registers, flag, memory), invalid_argument);
}

TEST_F(ArithmeticTestFixture, Add_Validation_Memory)
{
	registers['H']="GG";
	registers['L']="DD";
	EXPECT_THROW(ADD("M", registers, flag, memory), invalid_argument);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}