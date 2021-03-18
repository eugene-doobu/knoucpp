#include <iostream>

struct PassengerCar {
	char model[20];
	int year;
	int odometer;
};

void InputStruct(PassengerCar* car, const char* _model, int _year, int _odometer) {
	strcpy_s(car->model, _model);
	car->year = _year;
	car->odometer = _odometer;
}

int main() {
	PassengerCar car;
	InputStruct(&car, "eugene", 1997, 21);

	std::cout << "My car: " << car.model << ", " << car.year << ", " << car.odometer << std::endl;

	return 0;
}