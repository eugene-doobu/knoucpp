#include <iostream>
#include <iomanip>
using namespace std;

class Fraction {
	double numerator, denominator;
public:
	Fraction(double nemerator, double denominator): numerator{ nemerator } {
		if (denominator == 0) {
			this->denominator = 0.001; // 예외처리
		}
		else {
			this->denominator = denominator;
		}
	}

	// 사칙연산의 결과를 효율적으로 받기위해 이동연산자 정의
	Fraction(Fraction&& frac) : 
		numerator{ frac.numerator }, denominator{frac.denominator } {}

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

int main() {
	Fraction f1(2, 6);
	Fraction f2(3, 6);
	Fraction add(f1.Add(f2));

	cout << "(2/6) + (3/6)" << endl;
	add.Display();

	Fraction f3(3, 7);
	cout << "(5/6) - (3/7)" << endl;
	Fraction sub(add.Sub(f3));
	sub.Display();

	cout << "(5/6) * (3/7)" << endl;
	Fraction mul(add.Mul(f3));
	mul.Display();

	cout << "(5/6) / (3/7)" << endl;
	Fraction div(add.Div(f3));
	div.Display();
	return 0;
}
