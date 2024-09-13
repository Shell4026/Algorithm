#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

std::vector<std::vector<int>> arr{};
std::vector<std::vector<int>> dp{};

inline int Solve(int x1, int y1, int x2, int y2)
{
	--x1; --y1; --x2; --y2;
	int ans{0};
	if (x1 == 0 && y1 == 0)
		ans = dp[x2][y2];
	else if (x1 == 0)
		ans = dp[x2][y2] - dp[x2][y1 - 1];
	else if (y1 == 0)
		ans = dp[x2][y2] - dp[x1 - 1][y2];
	else
		ans = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
	return ans;
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int size{ 0 };
	int n{ 0 };
	std::cin >> size >> n;

	arr.resize(size, std::vector<int>(size, 0));
	dp.resize(size, std::vector<int>(size, 0));

	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
			std::cin >> arr[x][y];

			if (x - 1 < 0 && y - 1 < 0) //1행 1열
				dp[x][y] = arr[x][y];
			else if (x - 1 < 0) //1행
				dp[x][y] = dp[x][y - 1] + arr[x][y];
			else if (y - 1 < 0) //1열
				dp[x][y] = dp[x - 1][y] + arr[x][y];
			else
				dp[x][y] = dp[x][y - 1] + dp[x - 1][y] - dp[x - 1][y - 1] + arr[x][y];
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		int x1, x2, y1, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		std::cout << Solve(y1, x1, y2, x2) << '\n';
	}
	return 0;
}