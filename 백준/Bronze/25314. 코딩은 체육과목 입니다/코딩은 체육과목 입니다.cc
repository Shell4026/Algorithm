#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(0);
	std::cin.tie(0);

	int byte;
	std::cin >> byte;
	int cnt = byte / 4;
	for (int i = 0; i < cnt; ++i)
		std::cout << "long ";
	std::cout << "int";
	return 0;
}
