#include <iostream>
#include <queue>


int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::priority_queue<int> pq;

	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		if (num == 0)
		{
			if (pq.empty())
				std::cout << 0 << '\n';
			else
			{
				std::cout << pq.top() << '\n';
				pq.pop();
			}
			continue;
		}
		pq.push(num);
	}

	return 0;
}