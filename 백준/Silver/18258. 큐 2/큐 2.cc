#include <iostream>
#include <string>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		std::string cmd;
		std::cin >> cmd;
		if (cmd == "push")
		{
			int num;
			std::cin >> num;
			q.push(num);
		}
		else if (cmd == "pop")
		{
			if (q.empty())
				std::cout << -1 << '\n';
			else
			{
				std::cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (cmd == "size")
			std::cout << q.size() << '\n';
		else if (cmd == "empty")
			std::cout << (q.empty() ? 1 : 0) << '\n';
		else if (cmd == "front")
		{
			if (q.empty())
				std::cout << -1 << '\n';
			else
				std::cout << q.front() << '\n';
		}
		else
		{
			if (q.empty())
				std::cout << -1 << '\n';
			else
				std::cout << q.back() << '\n';
		}
	}
	return 0;
}
