#include <iostream>
#include <iomanip>
using namespace std;

class Fraction {
	double numerator, denominator;
public:
	Fraction(double nemerator, double denominator) : numerator{ nemerator } {
		if (denominator == 0) {
			this->denominator = 0.001; // 예외처리
		}
		else {
			this->denominator = denominator;
		}
	}

	Fraction operator+(const Fraction& c) const;
	Fraction operator-(const Fraction& c) const;
	Fraction operator*(const Fraction& c) const;
	Fraction operator/(const Fraction& c) const;

	// 사칙연산의 결과를 효율적으로 받기위해 이동연산자 정의
	Fraction(Fraction&& frac) noexcept:
		numerator{ frac.numerator }, denominator{ frac.denominator } {}

	Fraction Add(Fraction& frac) const {
		Fraction tmp(1, 1);
		if (denominator == frac.denominator) {
			tmp.numerator = numerator + frac.numerator;
			tmp.denominator = denominator;
		}
		else {
			tmp.numerator = numerator * frac.denominator +
				frac.numerator * denominator;
			tmp.denominator = denominator * frac.denominator;
		}
		return tmp;
	}

	Fraction Sub(Fraction& frac) const {
		Fraction tmp(1, 1);
		if (denominator == frac.denominator) {
			tmp.numerator = numerator - frac.numerator;
			tmp.denominator = denominator;
		}
		else {
			tmp.numerator = numerator * frac.denominator -
				frac.numerator * denominator;
			tmp.denominator = denominator * frac.denominator;
		}
		return tmp;
	}

	Fraction Mul(Fraction& frac) const {
		Fraction tmp(numerator * frac.numerator,
			denominator * frac.denominator);
		return tmp;
	}

	Fraction Div(Fraction& frac) const {
		Fraction tmp(numerator * frac.denominator,
			denominator * frac.numerator);
		return tmp;
	}

	void Display() const {
		cout << "numerator :" << numerator << endl
			<< "denominator :" << denominator << endl;
	}
};

Fraction Fraction::operator+(const Fraction& frac) const {
	Fraction tmp(1, 1);
	if (denominator == frac.denominator) {
		tmp.numerator = numerator + frac.numerator;
		tmp.denominator = denominator;
	}
	else {
		tmp.numerator = numerator * frac.denominator +
			frac.numerator * denominator;
		tmp.denominator = denominator * frac.denominator;
	}
	return tmp;
}

Fraction Fraction::operator-(const Fraction& frac) const {
	Fraction tmp(1, 1);
	if (denominator == frac.denominator) {
		tmp.numerator = numerator - frac.numerator;
		tmp.denominator = denominator;
	}
	else {
		tmp.numerator = numerator * frac.denominator -
			frac.numerator * denominator;
		tmp.denominator = denominator * frac.denominator;
	}
	return tmp;
}

Fraction Fraction::operator*(const Fraction& frac) const {
	Fraction tmp(numerator * frac.numerator,
		denominator * frac.denominator);
	return tmp;
}

Fraction Fraction::operator/(const Fraction& frac) const {
	Fraction tmp(numerator * frac.denominator,
		denominator * frac.numerator);
	return tmp;
}

int main() {
	Fraction f1(2, 6);
	Fraction f2(3, 6);
	Fraction f3(3, 7);

	cout << "(2/6) + (3/6)" << endl;
	(f1 + f2).Display();

	cout << "(5/6) - (3/7)" << endl;
	(f1 + f2 - f3).Display();

	cout << "(5/6) * (3/7)" << endl;
	((f1 + f2) * f3).Display();

	cout << "(5/6) / (3/7)" << endl;
	((f1 + f2) / f3).Display();
	return 0;
}
