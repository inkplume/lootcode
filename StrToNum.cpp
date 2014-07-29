#include <iostream>

enum Status { kValid = 0, kInvalid };
int g_nStatus = kValid;

long long StrToInt(const char* digit, bool minus);
double StrToDec(const char* digit, bool minus);

double StrToNum(const char *str)
{
	g_nStatus = kInvalid;
	
	long long partInt = 0;
	double partDec = 0.0;
	double num = 0.0;

	if (str != NULL && *str != '\0')
	{
		bool minus = false;
		bool decimal = false;

		if (*str == '+')
			++str;
		else if (*str == '-')
		{
			++str;
			minus = true;
		}

		const char* pDecimal = str;
		while (*pDecimal != '\0' && *pDecimal != '.')
			++pDecimal;
		if (*pDecimal != '\0' && *pDecimal == '.')
		{
			++pDecimal;
			decimal = true;
		}
		
		if (*str != '\0')
		{
			partInt = StrToInt(str, minus);

			if ((g_nStatus == kValid) && decimal)
				partDec = StrToDec(pDecimal, minus);

			if (g_nStatus == kValid)
				num = (double)partInt + partDec;
		}
	}

	return num;
}

long long StrToInt(const char* digit, bool minus)
{
	g_nStatus = kInvalid;

	long long num = 0;
	int flag = minus ? -1 : 1;

	while (*digit != '\0' && *digit != '.')
	{
		if (*digit >= '0' && *digit <= '9')
		{
			num = num * 10 + flag * (*digit - '0');

			if ((!minus && num > 0x7FFFFFFF) ||
				(minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}

			++digit;
		}
		else
		{
			num = 0;
			break;
		}
	}

	if (*digit == '\0' || *digit == '.')
		g_nStatus = kValid;

	return num;
}

double StrToDec(const char* digit, bool minus)
{
	g_nStatus = kInvalid;

	double weight = 10;
	double num = 0.0;
	int flag = minus ? -1 : 1;

	while (*digit != '\0')
	{
		if (*digit >= '0' && *digit <= '9')
		{
			num = num + flag * (*digit - '0') / weight;
			weight *= 10;
			++digit;
		}
		else
		{
			num = 0.0;
			break;
		}
	}

	if (*digit == '\0')
		g_nStatus = kValid;

	return num;
}

void Test(char* string)
{
    double result = StrToNum(string);

    if(result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %f.\n", string, result);
}

int main(int argc, char* argv[])
{
    Test(NULL);

    Test("");

    Test("123");

    Test("+123");
    
    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");    

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");    

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

	//测试小数
	printf("\n\n\nTest doblbe.\n");
	Test("123.123");
	Test("+123.123");
	Test("-123.123");
	Test("1a3.123");
	Test("123.1a3");
	Test("123.123.123");
	Test("0.123456789");
	Test("-0.123456789");

    return 0;
}
