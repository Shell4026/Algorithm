#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	int nc = 0;
	int tmp = n;
	while (tmp > 0)
	{
		++nc;
		tmp /= 10;
	}
	int min_n = tmp - 9 * nc;
	for (int i = min_n; i < n; ++i)
	{
		int s = i;
		int tmp = s;
		while (tmp > 0)
		{
			s += tmp % 10;
			tmp /= 10;
		}
		if (s == n)
		{
			std::cout << i;
			return 0;
		}
	}
	std::cout << 0;
	return 0;
}
