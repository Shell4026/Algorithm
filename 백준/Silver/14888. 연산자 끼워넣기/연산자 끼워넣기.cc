#include <iostream>
#include <vector>
#include <array>
#include <climits>

void solve(std::vector<int>&arr, std::array<int, 4> &op, int& max, int& min, int result = 0, int depth = 0)
{
	if (depth == 0)
		result = arr[0];
	if (depth == arr.size() - 1)
	{
		if (result < min)
			min = result;
		if (result > max)
			max = result;
		return;
	}
	for (int i = 0; i < op.size(); ++i)
	{
		if (op[i] == 0)
			continue;

		int c = 0;
		if (i == 0)
			c = result + arr[depth + 1];
		else if (i == 1)
			c = result - arr[depth + 1];
		else if (i == 2)
			c = result * arr[depth + 1];
		else
			c = result / arr[depth + 1];

		--op[i];
		solve(arr, op, max, min, c, depth + 1);
		++op[i];
	}
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;

	std::vector<int> arr(n, 0);
	std::array<int, 4> op = {0, 0, 0, 0};
	for (int i = 0; i < n; ++i)
	{
		int input;
		std::cin >> input;
		arr[i] = input;
	}
	for (int i = 0; i < op.size(); ++i)
	{
		int input;
		std::cin >> input;
		op[i] = input;
	}

	int max = INT_MIN;
	int min = INT_MAX;
	solve(arr, op, max, min);
	std::cout << max << '\n';
	std::cout << min;
	return 0;
}
