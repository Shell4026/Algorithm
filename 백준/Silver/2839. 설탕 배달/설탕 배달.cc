#include <iostream>

int dfs(int depth, int sum, int n)
{
	if (sum > n)
		return -1;
	if (sum == n)
		return depth;
	if (sum < n)
	{
		int d = dfs(depth + 1, sum + 5, n);
		if (d != -1)
			return d;
		d = dfs(depth + 1, sum + 3, n);
		if (d != -1)
			return d;
	}
}

int main()
{
	int n = 0;
	int result = 0;

	std::cin >> n;

	result = dfs(0, 0, n);
	std::cout << result;
	return 0;
}
