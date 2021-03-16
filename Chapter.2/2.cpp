#include <iostream>

class WAM {
private:
	float meter;
public:
	WAM(float _meter) {
		meter = _meter;
	}
	float GetMeter() {
		return meter;
	}
	float GetCentiMeter() {
		return meter * 100;
	}
	float GetInch() {
		return meter * 39.37f;
	}
	float GetFeet() {
		return meter * 3.28f;
	}
};

int main() {
	WAM myWam = WAM(1);
	std::cout <<
		myWam.GetMeter()      << std::endl <<
		myWam.GetCentiMeter() << std::endl <<
		myWam.GetInch()       << std::endl <<
		myWam.GetFeet()       << std::endl;
}