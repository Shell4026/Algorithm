#include <iostream>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		int n;
		std::cin >> n;
		sum += n * n;
	}

	std::cout << sum % 10;
	return 0;
}
