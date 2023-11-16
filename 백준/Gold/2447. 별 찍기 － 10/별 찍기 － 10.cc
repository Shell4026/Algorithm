#include <iostream>
#include <vector>
#include <cmath>

void Solve(std::vector<std::vector<bool>>& v, int x, int y, int size)
{
	if (size == 3)
	{
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				v[y + j][x + i] = true;
		v[y + 1][x + 1] = false;
		return;
	}
	int d = size / 3;
	Solve(v, x, y, d);
	Solve(v, x + d, y, d);
	Solve(v, x + 2 * d, y, d);
	Solve(v, x, y + d, d);
	for (int i = 0; i < d; ++i)
		for(int j = 0; j < d; ++j)
			v[y + d + j][x + d + i] = false;
	Solve(v, x + 2 * d, y + d, d);
	Solve(v, x, y + 2 * d, d);
	Solve(v, x + d, y + 2 * d, d);
	Solve(v, x + 2 * d, y + 2 * d, d);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::vector<std::vector<bool>> v(n, std::vector<bool>(n, false));
	Solve(v, 0, 0, n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] == true)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
