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
	// Euclidean Algorithm
	inline TYPE getGreatestCommonDivisor(void) const {
		TYPE m(numerator);
		TYPE n(denominator);

		while (n) {
			TYPE tmp(n);
			n = m % n;
			m = tmp;
		}

		return m;
	}

public:
	Fraction(void) : sign(true), numerator(0), denominator(1) { updateSign(); }
	Fraction(TYPE numerator_, TYPE denominator_) : sign(true), numerator(numerator_), denominator(denominator_) { updateSign(); reduce(); }

	inline TYPE getNumerator(void) const { return numerator; }
	inline TYPE getDenominator(void) const { return denominator; }
	inline void reduce(void) {
		TYPE n;

		while ((n = getGreatestCommonDivisor()) != 1) {
			numerator /= n;
			denominator /= n;
		}
	}
	inline Fraction<TYPE> operator-(void) const {
		Fraction<TYPE> fraction(*this);
		fraction.sign = fraction.sign ? false : true;
		return fraction;
	}
	inline void operator+=(const Fraction<TYPE>& fraction_) {
		Fraction<TYPE> fraction(fraction_);
		if (!sign)
			numerator *= -1;
		if (!fraction.sign)
			fraction.numerator *= -1;
		sign = true;
		TYPE tmp = fraction.denominator;
		fraction.denominator *= denominator;
		fraction.numerator *= denominator;
		denominator *= tmp;
		numerator *= tmp;
		numerator += fraction.numerator;
		updateSign();
		reduce();
	}
	inline void operator-=(const Fraction<TYPE>& fraction) {
		operator+=(-fraction);
	}

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

