#ifndef ___Class_Fraction
#define ___Class_Fraction

#include <iostream>

template <typename TYPE>
class Fraction {
private:
	TYPE numerator;
	TYPE denominator;
public:
	Fraction(void) : numerator(0), denominator(1) {}
	Fraction(TYPE numerator_, TYPE denominator_) : numerator(numerator_), denominator(denominator_) {}
	inline TYPE getNumerator(void) const { return numerator; }
	inline TYPE getDenominator(void) const { return denominator; }

	friend std::ostream& operator<<(std::ostream& os, const Fraction<TYPE>& fraction) {
		os << fraction.numerator;
		os << " / ";
		os << fraction.denominator;

		return os;
	}
};

#endif

