#include <iostream>

#include "NumericalCalculation/Value/Fraction.h"

using namespace std;

int main(int argc, char** argv)
{
	Fraction<int> a(5, 6);

	cout << a << endl;

	return 0;
}

