#include <iostream>
#include <array>

std::array<std::array<int, 15>, 15> dp;

void Solution(int a, int b)
{
	if (a == 0)
	{
		dp[a][b] = b;
		return;
	}
	if (dp[a][b] == 0)
	{
		for (int i = 1; i <= b; ++i)
		{
			if (dp[a - 1][i] == 0)
				Solution(a - 1, i);
			dp[a][b] += dp[a - 1][i];
		}
	}
}
int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 15; ++j)
			dp[i][j] = 0;
	for (int i = 0; i < t; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		
		Solution(a, b);
		std::cout << dp[a][b] << '\n';
	}

	return 0;
}