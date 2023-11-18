#include <iostream>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int type = -1;
	int before = 0;
	int next = 0;
	for (int i = 0; i < 8; ++i)
	{
		int n;
		std::cin >> n;

		if (i == 0)
		{
			if (n == 1)
				type = 0;
			else if (n == 8)
				type = 1;
			else
				type = 2;
		}
		else
		{
			if (type == 0)
			{
				if (n - before != 1)
				{
					type = 2;
					break;
				}
			}
			else if (type == 1)
			{
				if (n - before != -1)
				{
					type = 2;
					break;
				}
			}
		}
		before = n;
	}
	if (type == 0)
		std::cout << "ascending";
	else if (type == 1)
		std::cout << "descending";
	else
		std::cout << "mixed";
	return 0;
}
