#include <iostream>
#include <vector>

int main()
{
	std::cout.tie(0)->sync_with_stdio(false);
	std::cin.tie(0);

	std::vector<int> nums;
	std::vector<int> dp;
	int n = 0;
	int m = 0;
	int max_num = 0;
	std::cin >> n;
	nums.resize(n, 0);
	dp.resize(n, 0);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> m;
		nums[i] = m;
	}

	dp[0] = nums[0];
	max_num = dp[0];

	for (int i = 1; i < n; ++i)
	{
		dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
		max_num = (dp[i] > max_num) ? dp[i] : max_num;
	}

	std::cout << max_num;
	return 0;
}
