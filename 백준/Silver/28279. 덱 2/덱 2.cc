#include <iostream>
#include <string>
#include <deque>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::deque<int> dq;
	for (int i = 0; i < n; ++i)
	{
		int cmd;
		std::cin >> cmd;
		switch (cmd)
		{
		case 1:
		{
			int num;
			std::cin >> num;
			dq.push_front(num);
			break;
		}
		case 2:
		{
			int num;
			std::cin >> num;
			dq.push_back(num);
			break;
		}
		case 3:
			if (dq.empty())
				std::cout << -1 << '\n';
			else
			{
				std::cout << dq.front() << '\n';
				dq.pop_front();
			}
			break;
		case 4:
			if (dq.empty())
				std::cout << -1 << '\n';
			else
			{
				std::cout << dq.back() << '\n';
				dq.pop_back();
			}
			break;
		case 5:
			std::cout << dq.size() << '\n';
			break;
		case 6:
			std::cout << (dq.empty() ? 1 : 0) << '\n';
			break;
		case 7:
			if (dq.empty())
				std::cout << -1 << '\n';
			else
				std::cout << dq.front() << '\n';
			break;
		case 8:
			if (dq.empty())
				std::cout << -1 << '\n';
			else
				std::cout << dq.back() << '\n';
			break;
		}
	}
	return 0;
}
