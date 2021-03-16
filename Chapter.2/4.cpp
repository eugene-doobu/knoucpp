int main() {
	int inVal = 0, sum = 0;
	while (inVal >= 0)
	{
		sum += inVal;
		std::cin >> inVal;
	}
	std::cout << sum << std::endl;
}