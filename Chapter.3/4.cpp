#include <iostream>
#include <iomanip>
using namespace std;

struct SalesRec {
	char pId[10];
	int dYear, dMonth, dDate;
	char deliverAddr[40];
};


int main() {
	SalesRec s[10];
	s[0] = { "No.0", 2019,  1,  1, "��ġ0" };
	s[1] = { "No.1", 2019,  2,  3, "��ġ1" };
	s[2] = { "No.2", 2019,  3,  5, "��ġ2" };
	s[3] = { "No.3", 2019,  4,  7, "��ġ3" };
	s[4] = { "No.4", 2019,  5,  9, "��ġ4" };
	s[5] = { "No.5", 2019,  6, 11, "��ġ5" };
	s[6] = { "No.6", 2019,  7, 13, "��ġ6" };
	s[7] = { "No.7", 2019,  8, 15, "��ġ7" };
	s[8] = { "No.8", 2019,  9, 17, "��ġ8" };
	s[9] = { "No.9", 2019, 10, 19, "��ġ9" };

	std::cout << "ǰ���ڵ�" << " �������" << " ����ּ�" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout <<
			setw(6) << s[i].pId <<
			setw(7) << s[i].dYear << setw(2) << s[i].dMonth << setw(2) << s[i].dDate <<
			setw(7) << s[i].deliverAddr <<
			std::endl;
	}

	return 0;
}