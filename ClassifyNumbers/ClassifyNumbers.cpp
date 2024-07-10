// ClassifyNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include<vector>


#include "CGenerateNumbers.h"
#include "CClassification.h"
#include "CCategoryAction.h"
#include "CNamedPipe.h"

using namespace std;






int main()
{


	CNamedPipe test;

	test.init();

	int x = 4;
	vector <unsigned int> Numbers;

	CGenerateNumbers  generateNumbers;
	CClassification   classification;
	CCategoryAction   categoryAction;

	generateNumbers.genrateNumbers(x, Numbers);
	for (auto num : Numbers) {

		categoryAction.takeAction(num ,classification.GetNumCategory(num));
	}
	


}

