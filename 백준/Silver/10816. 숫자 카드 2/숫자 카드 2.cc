#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	
	std::vector<int> cards(20000001, 0);
	for (int i = 0; i < n; ++i)
	{
		int card;
		std::cin >> card;
		++cards[card + 10000000];
	}
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int card;
		std::cin >> card;
		std::cout << cards[card + 10000000] << ' ';
	}
	return 0;
}
