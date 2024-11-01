#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> input(n, 0);

	for (int i = 0; i < n; ++i)
		std::cin >> input[i];

	std::vector<int> dp{ input[0] };

	for (int i = 1; i < n; ++i)
	{
		if (input[i] > dp.back())
			dp.push_back(input[i]);
		else
		{
			auto it = std::lower_bound(dp.begin(), dp.end(), input[i]);
			if (input[i] < *it)
				*it = input[i];
		}
	}
	std::cout << dp.size();
}
