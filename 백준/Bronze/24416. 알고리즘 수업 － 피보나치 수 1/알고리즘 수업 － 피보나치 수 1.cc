#include <iostream>
#include <vector>

int fib(int n, int &count)
{
	
	if (n == 0 || n == 1 || n == 2)
	{
		++count;
		return 1;
	}
	else
	{
		return fib(n - 1, count) + fib(n - 2, count);
	}
}
int fib(int n, std::vector<int> &dp, int &count)
{
	if (n == 0 || n == 1 || n == 2)
		return 1;
	if (dp[n - 1] == -1)
		dp[n - 1] = fib(n - 1, dp, count);
	if (dp[n - 2] == -1)
		dp[n - 2] = fib(n - 2, dp, count);
	++count;
	dp[n] = dp[n - 1] + dp[n - 2];
	return dp[n];
}

int main()
{
	std::cout.tie(0)->sync_with_stdio(false);
	std::cin.tie(0);

	int n = 0;
	std::cin >> n;

	std::vector<int> dp;
	dp.resize(n + 1, -1);

	int count = 0;
	fib(n, count);
	std::cout << count << ' ';
	count = 0;
	fib(n, dp, count);
	std::cout << count;
	return 0;
}
