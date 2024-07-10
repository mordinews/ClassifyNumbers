#pragma once
#include "CClassification.h"
#include "CGenerateNumbers.h"

#include<vector>

using namespace std;

enum PRINT_TYPE
{ 
	NORMAL,
	ACENDNIG,
	DECENDING,

};

class CCategoryAction
{

public:
	void takeAction(const unsigned int& num,CATEGORY category);

private:
	void printNum(const unsigned int& i);
	
	void generateXRandomNumbers(const unsigned int& num);

	unsigned int calcDigitsMultiplication(const unsigned int& i);

	void PrintVec(vector <unsigned int>& Numbers, PRINT_TYPE type);


	//for START_WITH_ONE
	vector <unsigned int>  m_Numbers;

	
};

