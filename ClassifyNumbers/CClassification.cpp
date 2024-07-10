#include "CClassification.h"
#include <iostream>
#include <string>

using namespace std;


CATEGORY CClassification::GetNumCategory(const unsigned int& num)
{
	if (IsOdd(num)) {
		return ODD_NUMBER;
	}
	else if (IsStartWithOne(num)) {
		return START_WITH_ONE;
	}
	else if (IsContainThreeDigits(num)) {
		return CONTAIN_ONLY_THREE_DIGITS;
	}
	else {
		return DEFAULT;
	}
}


bool CClassification::IsOdd(const unsigned int& num)
{
	return (num % 2 == 1);
}

bool CClassification::IsStartWithOne(const unsigned int& num)
{
	string str = to_string(num);

	if (str[0] =='1')
	{
		return true;
	}
	return false;
}

bool CClassification::IsContainThreeDigits(const unsigned int& num)
{
	string str = to_string(num);
	if (str.size() == 3) {
		return true;
	}

	return false;
}