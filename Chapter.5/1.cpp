
#pragma warning(disable:4996)

#include <iostream>
using namespace std;

class Pencils {
	int dozens;
	int np;
public:
	Pencils() : dozens(0), np(0) {};
	Pencils(int n) { dozens = n / 12; np = n % 12; }
	Pencils(int d, int n) : dozens(d), np(n) {};
	Pencils& operator++();
	Pencils operator++(int);
	Pencils operator+(const Pencils& pencils) const;
	Pencils operator-(const Pencils& pencils) const;
	void display() const;
};

Pencils Pencils::operator+(const Pencils& pencils) const {
	Pencils tmp;
	tmp.dozens = this->dozens + pencils.dozens;
	tmp.np = this->np + pencils.np;
	if (tmp.np >= 12) {
		++tmp.dozens;
		tmp.np -= 12;
	}
	return tmp;
}

Pencils Pencils::operator-(const Pencils& pencils) const {
	Pencils tmp;
	tmp.dozens = this->dozens - pencils.dozens;
	tmp.np = this->np - pencils.np;
	if (tmp.np < 0 && tmp.dozens > 0) {
		--tmp.dozens;
		tmp.np += 12;
	}
	if (tmp.np > 0 && tmp.dozens < 0) {
		++tmp.dozens;
		tmp.np -= 12;
	}
	return tmp;
}

Pencils& Pencils::operator++() {
	if (++np >= 12)
		++dozens, np = 0;
	return *this;
}

Pencils Pencils::operator++(int) {
	Pencils tmp(*this);
	if (++np >= 12)
		++dozens, np = 0;
	return tmp;
}

void Pencils::display() const {
	if (dozens) {
		cout << dozens << "타";
		if (np) cout << np << "자루";
		cout << endl;
	}
	else {
		cout << np << "자루" << endl;
	}
}

int main()
{
	Pencils p1(5, 7);
	Pencils p2(23);

	p1.display();
	(++p1).display();
	p1.display();
	cout << endl;

	p2.display();
	p1 = p2++;
	p1.display();
	p2.display();

	cout << endl;
	Pencils p3 = p1 + p2;
	Pencils p4 = p1 - p2;
	Pencils p5 = p2 - p1;
	p3.display();
	p4.display();
	p5.display();
	return 0;
}
