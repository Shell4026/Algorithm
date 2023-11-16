#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(0);
	std::cin.tie(0);

	int a, b, c, d, e, f;
	int x = 0, y = 0;
	std::cin >> a >> b >> c >> d >> e >> f;
	
	if (a == 0)
	{
		if (e == 0)
		{
			x = f / d;
			y = c / b;
			std::cout << x << ' ' << y;
			return 0;
		}
		else
		{
			y = c / b;
			x = (f - e * y) / d;
			std::cout << x << ' ' << y;
			return 0;
		}
	}
	if (b == 0)
	{
		if (d == 0)
		{
			x = c / a;
			y = f / e;
			std::cout << x << ' ' << y;
			return 0;
		}
		else
		{
			x = c / a;
			y = (f - d * x) / e;
			std::cout << x << ' ' << y;
			return 0;
		}
	}
	for (int i = -999; i <= 999; ++i)
	{
		for (int j = -999; j <= 999; ++j)
		{
			int res = a * i + b * j;
			int res2 = d * i + e * j;
			if (res == c && res2 == f)
			{
				std::cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}