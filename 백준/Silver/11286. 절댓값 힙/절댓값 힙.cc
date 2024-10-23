#include <iostream>
#include <vector>
#include <queue>


int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::priority_queue<int, std::vector<int>, std::less<int>> pqNegative;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pqPositive;
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		if (num == 0)
		{
			if (pqNegative.empty() && pqPositive.empty())
				std::cout << 0 << '\n';
			else if (pqNegative.empty())
			{
				std::cout << pqPositive.top() << '\n';
				pqPositive.pop();
			}
			else if (pqPositive.empty())
			{
				std::cout << pqNegative.top() << '\n';
				pqNegative.pop();
			}
			else
			{
				int ntop = std::abs(pqNegative.top());
				int ptop = std::abs(pqPositive.top());
				if (ntop == ptop || ntop < ptop)
				{
					std::cout << pqNegative.top() << '\n';
					pqNegative.pop();
				}
				else if (ptop < ntop)
				{
					std::cout << pqPositive.top() << '\n';
					pqPositive.pop();
				}
			}
			continue;
		}
		else if (num > 0)
			pqPositive.push(num);
		else
			pqNegative.push(num);
	}

	return 0;
}