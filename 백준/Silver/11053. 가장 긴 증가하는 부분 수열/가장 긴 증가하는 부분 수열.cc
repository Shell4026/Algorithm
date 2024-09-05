#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <utility>

std::vector<int> input;
std::vector<int> dp;

auto Solution(int n) -> int
{
	dp.push_back(input[0]);
	for (int i = 1; i < n; ++i)
	{
		if (input[i] > dp.back())
		{
			dp.push_back(input[i]);
		}
		else
		{
			auto it = std::lower_bound(dp.begin(), dp.end(), input[i]);
			if (*it > input[i])
				*it = input[i];
		}
	}
	return dp.size();
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n = 0;
	std::cin >> n;
	input.resize(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> input[i];
	}

	std::cout << Solution(n);
	return 0;
}