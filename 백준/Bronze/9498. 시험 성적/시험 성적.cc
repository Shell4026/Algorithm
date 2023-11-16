#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(0);
	std::cin.tie(0);

	int score;
	std::cin >> score;
	if (score >= 90 && score <= 100)
		std::cout << 'A';
	else if (score >= 80 && score <= 89)
		std::cout << 'B';
	else if (score >= 70 && score <= 79)
		std::cout << 'C';
	else if (score >= 60 && score <= 69)
		std::cout << 'D';
	else
		std::cout << 'F';
	return 0;
}