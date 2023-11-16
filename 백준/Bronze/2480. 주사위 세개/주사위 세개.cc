#include <iostream>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(0);
	std::cin.tie(0);

	int a, b, c;
	std::cin >> a >> b >> c;

	if (a == b && b == c)
	{
		std::cout << 10000 + a * 1000;
	}
	else
	{
		if (a == b || a == c || b == c)
		{
			if(a == b)
				std::cout << 1000 + a * 100;
			else
				std::cout << 1000 + c * 100;
		}
		else
		{
			std::cout << std::max({ a, b, c }) * 100;
		}
	}
	return 0;
}
