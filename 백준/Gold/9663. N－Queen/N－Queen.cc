#include <iostream>
#include <vector>
#include <cmath>

int count = 0;
struct Pos
{
	int x, y;
	Pos()
	{
		x = -1;
		y = -1;
	}
	Pos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool check_place(int my_x, int my_y, int other_x, int other_y)
{
	if (my_x == other_x || my_y == other_y)
		return false;
	if (my_y - my_x == other_y - other_x)
		return false;
	if (my_x + my_y == other_x + other_y)
		return false;
	return true;
}

void solve(std::vector<Pos>& queens, int n, int depth = 0)
{
	for (int i = 0; i < n; ++i)
	{
		bool skip = false;
		for (int j = 0; j < depth; ++j)
		{
			if (!check_place(i, depth, queens[j].x, queens[j].y))
			{
				skip = true;
				break;
			}
		}
		if (skip)
			continue;

		if (depth == n - 1)
		{
			++count;
			return;
		}
		queens[depth] = Pos(i, depth);
		solve(queens, n, depth + 1);
		queens[depth] = Pos();
	}
	return;
}

int main()
{
	std::cin.tie(0);
	std::iostream::sync_with_stdio(false);

	int n = 0;
	std::cin >> n;
	std::vector<Pos> queens(n, Pos());

	solve(queens, n);
	std::cout << count;
	return 0;
}
