
#include <iostream>
#include <string>
#include <chrono>

void solve(int n)
{
	if (n == 1)
	{
		std::cout << 666;
		return;
	}
	int cnt = 2;
	for (int i = 1; i < n; ++i)
	{
		std::string prefix = std::to_string(i);
		int end = prefix.size() - 1;
		if (prefix.find("666") != std::string::npos)
		{
			for (int j = 0; j < 1000; ++j)
			{
				if (cnt++ == n)
				{
					if (j < 10)
						std::cout << prefix + "00" + std::to_string(j) << '\n';
					else if (j < 100)
						std::cout << prefix + "0" + std::to_string(j) << '\n';
					else
						std::cout << prefix + std::to_string(j) << '\n';
					return;
				}
			}
		}
		else
		{
			if (prefix.back() == '6')
			{
				int end = prefix.size() - 1;
				if (prefix[end - 1] == '6')
				{
					if (prefix[end - 2] == '6')
					{
						for (int j = 0; j < 1000; ++j)
						{
							if (cnt++ == n)
							{
								if (j < 10)
									std::cout << prefix + "00" + std::to_string(j) << '\n';
								else if (j < 100)
									std::cout << prefix + "0" + std::to_string(j) << '\n';
								else
									std::cout << prefix + std::to_string(j) << '\n';
								return;
							}
						}
					}
					else // prefix[end - 2] == '6'
					{
						for (int j = 0; j < 100; ++j)
						{
							if (cnt++ == n)
							{
								if (j < 10)
									std::cout << prefix + "60" + std::to_string(j) << '\n';
								else
									std::cout << prefix + "6" + std::to_string(j) << '\n';
								return;
							}
						}
					}
				}
				else // prefix[end - 1] == '6'
				{
					for (int j = 0; j < 10; ++j)
					{
						//std::cout << prefix + "66" + std::to_string(j) << '\n';
						if (cnt++ == n)
						{
							std::cout << prefix + "66" + std::to_string(j) << '\n';
							return;
						}
					}
				}
			}
			else
			{
				//std::cout << prefix + "666\n";
				if (cnt++ == n)
				{
					std::cout << prefix + "666\n";
					return;
				}
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	solve(n);
	return 0;
}
