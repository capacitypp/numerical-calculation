#include <iostream>

#include "NumericalCalculation/Value/Fraction.h"

using namespace std;
using namespace NumericalCalculation;

int main(int argc, char** argv)
{
	Fraction<int> a(125, 9);
	Fraction<int> b(-405, 125);

	a *= b;

	cout << a << endl;

	return 0;
}

