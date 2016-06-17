#include <iostream>

#include "NumericalCalculation/Value/Fraction.h"

using namespace std;
using namespace NumericalCalculation;

int main(int argc, char** argv)
{
	Fraction<int> a(3, 5);
	Fraction<int> b(-2, 3);

	a += b;

	cout << a << endl;

	return 0;
}

