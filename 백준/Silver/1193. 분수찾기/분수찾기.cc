#include <iostream>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int num;
	std::cin >> num;

	int length = 1;
	int n = 1; //분자
	int d = 1; //분모
	for (int i = 0, cnt = 1; i < num - 1; ++i)
	{
		if (length % 2 == 1)
		{
			if (cnt == length)
			{
				//std::cout << n << '/' << d << '\n';
				++d;
				length += 1;
				cnt = 1;
				continue;
			}
			//std::cout << n << '/' << d << '\n';
			--n;
			++d;
			++cnt;
		}
		else
		{
			if (cnt == length)
			{
				//std::cout << n << '/' << d << '\n';
				++n;
				length += 1;
				cnt = 1;
				continue;
			}
			//std::cout << n << '/' << d << '\n';
			++n;
			--d;
			++cnt;
		}
	}
	std::cout << n << '/' << d;
	return 0;
}
