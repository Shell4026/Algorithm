#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(0);
	std::cin.tie(0);

	int cnt;
	std::cin >> cnt;

	std::priority_queue<int, std::vector<int>, std::less<int>> max;
	std::priority_queue<int, std::vector<int>, std::greater<int>> min;

	for (int i = 0; i < cnt; ++i)
	{
		int n;
		std::cin >> n;
		
		if (max.size() <= min.size())
		{
			max.push(n);
		}
		else
			min.push(n);
		if (min.size() != 0)
		{
			if (max.top() > min.top())
			{
				int max_top = max.top();
				int min_top = min.top();
				max.pop();
				min.pop();
				max.push(min_top);
				min.push(max_top);
			}
		}
		std::cout << max.top() << '\n';
	}

	return 0;
}
