#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> input(n, 0);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> input[i];
	}

	std::sort(input.begin(), input.end());
	
	int lastSum = input[0];
	int sum = lastSum;
	for (int i = 1; i < n; ++i)
	{
		lastSum = input[i] + lastSum;
		sum += lastSum;
	}
	std::cout << sum;
	return 0;
}