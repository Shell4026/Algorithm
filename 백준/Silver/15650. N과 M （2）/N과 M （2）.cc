#include <iostream>
#include <vector>

int arr[9] = { 0, };
void solve(std::vector<bool>& mem, int n, int m, int depth = 0)
{
	if (depth == m)
	{
		for (int i = 0; i < m; ++i)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		if (arr[depth - 1] > i + 1)
			continue;
		if (mem[i])
			continue;
		else
			arr[depth] = i + 1;

		mem[i] = true;
		solve(mem, n, m, depth + 1);
		mem[i] = false;
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<bool> mem(n, false);
	solve(mem, n, m);
	return 0;
}
