#include <iostream>
#include <deque>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::deque<int> dq;
	std::vector<int> v(n, 0);

	for (int i = 0; i < n; ++i)
	{
		int type;
		std::cin >> type;
		v[i] = type;
	}
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		if (v[i] == 0)
		{
			dq.push_back(num);
		}
	}

	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;

		dq.push_front(num);
		int ret = dq.back();
		dq.pop_back();
		std::cout << ret << ' ';
	}
	return 0;
}
