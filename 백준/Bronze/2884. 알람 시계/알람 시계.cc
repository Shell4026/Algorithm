#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(0);
	std::cin.tie(0);

	int h, m;
	std::cin >> h >> m;

	m -= 45;
	if (m < 0)
	{
		m = 60 + m;
		h -= 1;
	}
	if (h < 0)
		h = 24 + h;

	std::cout << h << ' ' << m;
	return 0;
}
