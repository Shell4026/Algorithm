#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> input(n, 0);
	for (int i = 0; i < n; ++i)
		std::cin >> input[i];

	int cnt = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == 1)
		{
			continue;
		}
		bool pass = false;
		for (int j = 2; j < 1000; ++j)
		{
			if (input[i] <= j)
				break;

			if (input[i] % j == 0)
			{
				pass = true;
				break;
			}
		}
		if (pass)
			continue;
		++cnt;
	}
	std::cout << cnt;
}
