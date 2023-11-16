#include <iostream>
#include <vector>

int arr[9] = { 0, };
void solve(int n, int m, int depth = 0)
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
		arr[depth] = i + 1;
		solve( n, m, depth + 1);
	}
}

int main()
{
	std::cin.tie(0);
	std::iostream::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	solve(n, m);
	return 0;
}
