#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1 - i ; ++j)
			std::cout << ' ';
		for (int j = 0; j < 2 * i + 1; ++j)
			std::cout << '*';
		std::cout << '\n';
	}
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
			std::cout << ' ';
		for (int j = 0; j < 2 * (n - 2 - i) + 1; ++j)
			std::cout << '*';
		std::cout << '\n';
	}
	return 0;
}
