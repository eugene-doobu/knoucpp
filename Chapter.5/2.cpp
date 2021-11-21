#pragma warning(disable:4996)

#include <iostream>
using namespace std;

class Complex2 {
	double rPart, iPart;
public:
	Complex2(double r = 0, double i = 0) :rPart(r), iPart(i) {};
	Complex2 operator+(const Complex2& c) const;
	Complex2 operator-(const Complex2& c) const;
	Complex2 operator*(const Complex2& c) const;
	Complex2 operator/(const Complex2& c) const;

	Complex2& operator+=(const Complex2& c);
	Complex2& operator-=(const Complex2& c);
	Complex2& operator*=(const Complex2& c);
	Complex2& operator/=(const Complex2& c);

	bool operator==(const Complex2& c) const;
	bool operator!=(const Complex2& c) const;

	void Print() {
		cout << "rPart: " << rPart << ", iPart: " << iPart << endl;
	}
};

Complex2 Complex2::operator+(const Complex2& c) const {
	return Complex2(rPart + c.rPart, iPart + c.iPart);
}

Complex2 Complex2::operator-(const Complex2& c) const {
	return Complex2(rPart - c.rPart, iPart - c.iPart);
}

Complex2 Complex2::operator*(const Complex2& c) const {
	return Complex2(rPart * c.rPart - iPart * c.iPart, iPart * c.rPart + rPart * c.iPart);
}

Complex2 Complex2::operator/(const Complex2& c) const {
	double d = c.rPart * c.rPart + c.iPart * c.iPart;
	Complex2 tmpC = Complex2(rPart, iPart) * Complex2(c.rPart, -c.iPart);
	return Complex2(tmpC.rPart/d, tmpC.iPart/d);
}

Complex2& Complex2::operator+=(const Complex2& c) {
	rPart += c.rPart;
	iPart += c.iPart;
	return *this;
}

Complex2& Complex2::operator-=(const Complex2& c) {
	rPart -= c.rPart;
	iPart -= c.iPart;

	return *this;
}

Complex2& Complex2::operator*=(const Complex2& c) {
	double _rPart = rPart * c.rPart - iPart * c.iPart;
	double _iPart = iPart * c.rPart + rPart * c.iPart;
	rPart = _rPart;
	iPart = _iPart;
	return *this;
}

Complex2& Complex2::operator/=(const Complex2& c) {
	double d = c.rPart * c.rPart + c.iPart * c.iPart;
	Complex2 tmpC = Complex2(rPart, iPart) * Complex2(c.rPart, -c.iPart);
	rPart = tmpC.rPart / d;
	iPart = tmpC.iPart / d;
	return *this;
}

bool Complex2::operator==(const Complex2& c) const {
	return rPart == c.rPart && iPart == c.iPart;
}

bool Complex2::operator!=(const Complex2& c) const {
	return !(rPart == c.rPart && iPart == c.iPart);
}

int main()
{
	auto comp1 = Complex2(2, 3);
	comp1.Print();
	cout << endl;

	auto comp2 = comp1 + Complex2(3, 4);
	comp2.Print();
	auto comp3 = comp2 - comp1;
	comp3.Print();
	auto comp4 = Complex2(2, 3) * Complex2(4, 5);
	comp4.Print();
	auto comp5 = Complex2(1, 1) / Complex2(1, -1);
	comp5.Print();

	cout << endl;
	(comp1 += Complex2(3, 4)          ).Print(); // comp1이 변화되었음에 주의
	(comp2 -= comp1                   ).Print(); // comp2가 변화되었음에 주의
	(Complex2(2, 3) *= Complex2(4, 5) ).Print();
	(Complex2(1, 1) /= Complex2(1, -1)).Print();

	cout << endl;
	cout << (Complex2(2, 3) == Complex2(4, 5)) << endl;
	cout << (Complex2(2, 3) != Complex2(4, 5)) << endl;
	return 0;
}
