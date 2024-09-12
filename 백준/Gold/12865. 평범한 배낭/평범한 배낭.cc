#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

std::vector<std::pair<int, int>> input;
std::vector<std::vector<int>> dp;

int Solve(int i, int weight)
{
	if (i == 0)
	{ 
		if (input[i].first <= weight)
		{
			return input[i].second;
		}
		return 0;
	}
		
	if (dp[i - 1][weight] == 0)
		dp[i - 1][weight] = Solve(i - 1, weight);

	if (weight >= input[i].first)
	{
		if (dp[i - 1][weight - input[i].first] == 0)
			dp[i - 1][weight - input[i].first] = Solve(i - 1, weight - input[i].first);

		dp[i][weight] = std::max(dp[i - 1][weight], input[i].second + dp[i - 1][weight - input[i].first]);
	}
	else
	{
		dp[i][weight] = dp[i - 1][weight];
	}
	return dp[i][weight];
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, maxWeight;
	std::cin >> n >> maxWeight;

	input.resize(n);
	dp.resize(n, std::vector<int>(maxWeight + 1, 0));

	for (int i = 0; i < n; ++i)
	{
		std::pair<int, int> data;
		std::cin >> data.first >> data.second;
		input[i] = data;
	}

	std::cout << Solve(n - 1, maxWeight);
	return 0;
}