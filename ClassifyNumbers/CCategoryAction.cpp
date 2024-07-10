#include "CCategoryAction.h"

#include <iostream>
#include <string>

using namespace std;



void CCategoryAction::takeAction(const unsigned int& num,CATEGORY category)
{
	switch (category)
	{
	case ODD_NUMBER:

		printNum(num);
		cout << " : this is an odd number"<<endl;
		break;

	case START_WITH_ONE:

		cout << num << " : starts with 1";
		generateXRandomNumbers(num);
		break;

	case CONTAIN_ONLY_THREE_DIGITS:

		cout << num << " : the digit’s multiplications are equal to ";
		printNum(calcDigitsMultiplication(num));
		break;

	default:
		cout << num <<" : this number belongs to the others";
		break;

	}

}

void CCategoryAction::printNum(const unsigned int& num)
{
	cout << num <<endl;
}

void CCategoryAction::PrintVec(vector <unsigned int>& Numbers, PRINT_TYPE type)
{

	if (type == ACENDNIG) {
		sort(Numbers.begin(), Numbers.end());
	}

	for (auto num : Numbers) {
		cout << num << " ";
	}

	cout << endl;
}

void CCategoryAction::generateXRandomNumbers(const unsigned int& num)
{
	CGenerateNumbers genNum;

	genNum.genrateNumbers(num,m_Numbers);

	PrintVec(m_Numbers, NORMAL);
	
	PrintVec(m_Numbers, DECENDING);

	m_Numbers.clear();
}



unsigned int CCategoryAction::calcDigitsMultiplication(const unsigned int& num)
{
	unsigned int calc = (1 % num) * (10 % num) * (100 % num);
	return calc;
}
