#include <iostream>
#include <vector>
#include <cmath>

void Solve(int n, bool line)
{
	if (!line)
	{
		for (int i = 0; i < n; ++i)
			std::cout << ' ';
		return;
	}
	if (n == 1)
	{
		if (line)
			std::cout << '-';
		else
			std::cout << ' ';
		return;
	}
	Solve(n / 3, true);
	Solve(n / 3, false);
	Solve(n / 3, true);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	while (true)
	{
		int n;
		std::cin >> n;
		if (std::cin.eof())
			break;
		Solve(std::pow(3, n), true);
		std::cout << '\n';
	}
	return 0;
}
