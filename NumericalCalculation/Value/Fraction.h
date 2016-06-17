#ifndef ___Class_Fraction
#define ___Class_Fraction

#include <iostream>

namespace NumericalCalculation
{

template <typename TYPE>
class Fraction {
private:
	// A sign of the value
	// true : +
	// false : -
	bool sign;
	TYPE numerator;
	TYPE denominator;

private:
	inline void updateSign(void) {
		if (numerator < 0) {
			numerator *= -1;
			sign = sign ? false : true;
		}
		if (denominator < 0) {
			denominator *= -1;
			sign = sign ? false : true;
		}
	}

public:
	Fraction(void) : sign(true), numerator(0), denominator(1) { updateSign(); }
	Fraction(TYPE numerator_, TYPE denominator_) : sign(true), numerator(numerator_), denominator(denominator_) { updateSign(); }

	inline TYPE getNumerator(void) const { return numerator; }
	inline TYPE getDenominator(void) const { return denominator; }

	inline friend std::ostream& operator<<(std::ostream& os, const Fraction<TYPE>& fraction) {
		if (!fraction.sign)
			os << '-';
		os << fraction.numerator;
		os << " / ";
		os << fraction.denominator;

		return os;
	}
};

}

#endif

