#include <iostream>
#include <set>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::set<int> cards;

	int n, m;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int card;
		std::cin >> card;
		cards.insert(card);
	}

	std::cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int card;
		std::cin >> card;
		if (cards.find(card) == cards.end())
			std::cout << "0 ";
		else
			std::cout << "1 ";
	}
	return 0;
}
