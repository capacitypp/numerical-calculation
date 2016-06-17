#include <iostream>

#include "NumericalCalculation/Value/Fraction.h"

using namespace std;
using namespace NumericalCalculation;

int main(int argc, char** argv)
{
	Fraction<int> a(-30, -6);

	cout << a << endl;

	return 0;
}

