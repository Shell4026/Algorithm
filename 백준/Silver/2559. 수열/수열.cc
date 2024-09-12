#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

std::vector<int> input{};
std::vector<int> dp;

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, offset;
	std::cin >> n >> offset;
	int dpSize = n - offset + 1;

	input.resize(n);
	dp.resize(dpSize, 0);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> input[i];
	}

	for (int i = 0; i < offset; ++i)
	{
		dp[0] += input[i];
	}

	for (int i = 1; i < dpSize; ++i)
	{
		dp[i] = dp[i - 1] - input[i - 1] + input[i + offset - 1];
	}

	std::cout << *std::max_element(dp.begin(), dp.end());

	return 0;
}