#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
	
	int n, price;
	std::cin >> n >> price;

	std::vector<int> input(n, 0);
	for (int i = n - 1; i >= 0; --i)
	{
		std::cin >> input[i];
	}

	int lastMoney = price;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (input[i] > price)
			continue;
		
		while (lastMoney >= input[i])
		{
			lastMoney -= input[i];
			++cnt;
		}
	}
	
	std::cout << cnt;
	return 0;
}