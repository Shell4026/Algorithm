#include <iostream>
#include <string>

static int count = 0;
static std::string logs;

void hanoi(int n, int start, int sub, int goal)
{
	++count;
	if (n == 1)
	{
		logs += std::to_string(start) + ' ' + std::to_string(goal) + '\n';
		return;
	}

	hanoi(n - 1, start, goal, sub);
	logs += std::to_string(start) + ' ' + std::to_string(goal) + '\n';
	hanoi(n - 1, sub, start, goal);
}

int main()
{
	std::cout.tie(0)->sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;

	std::cin >> n;

	hanoi(n, 1, 2, 3);

	std::cout << count << '\n';
	std::cout << logs;
	return 0;
}
