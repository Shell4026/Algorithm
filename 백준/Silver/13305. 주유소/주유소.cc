#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	--n;

	uint64_t minPrice{ 0 };
	std::vector<int> dis(n);
	std::vector<int> price(n + 1);
	for (int i = 0; i < n; ++i)
		std::cin >> dis[i];
	for (int i = 0; i < n + 1; ++i)
		std::cin >> price[i];

	int currentPrice = price[0];
	for (int i = 0; i < n; ++i)
	{
		if (i + 1 == n)
		{
			minPrice += currentPrice * dis[i];
			break;
		}
		if (currentPrice > price[i + 1])
		{
			minPrice += currentPrice * dis[i];
			currentPrice = price[i + 1];
		}
		else
		{
			minPrice += currentPrice * dis[i];
		}
	}
	std::cout << minPrice;
	return 0;
}