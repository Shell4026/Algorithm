#include <iostream>
#include <array>
#include <vector>

typedef std::array<std::array<int, 9>, 9> Board;

struct Pos {
	int x, y;
	Pos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

std::vector<int> can_place(Board& board, int x, int y)
{
	std::vector<int> allow;
	for (int n = 1; n <= 9; ++n)
	{
		bool skip = false;
		for (int i = 0; i < 9; ++i)
		{
			if (board[y][i] == n)
			{
				skip = true;
				break;
			}
			if (board[i][x] == n)
			{
				skip = true;
				break;
			}
		}
		if (!skip)
		{
			int x_group = (x / 3) * 3;
			int y_group = (y / 3) * 3;
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (board[y_group + i][x_group + j] == n)
					{
						skip = true;
						break;
					}
				}
				if (skip)
					break;
			}
		}
		if (skip)
			continue;
		allow.push_back(n);
	}
	return allow;
}

bool solve(Board& board, std::vector<Pos>& emptys, int depth = 0)
{
	if (depth == emptys.size())
	{
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board.size(); ++j)
			{
				std::cout << board[i][j] << ' ';
			}
			std::cout << '\n';
		}
		return true;
	}
	int x = emptys[depth].x;
	int y = emptys[depth].y;
	auto v = can_place(board, x, y);
	for (int j = 0; j < v.size(); ++j)
	{
		board[y][x] = v[j];
		if (solve(board, emptys, depth + 1))
			return true;
		board[y][x] = 0;
	}
	return false;
}

int main()
{
	std::cin.tie(0);
	std::iostream::sync_with_stdio(false);

	Board board;

	std::vector<Pos> emptys;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			int num;
			std::cin >> num;
			board[i][j] = num;
			if (num == 0)
				emptys.push_back(Pos(j, i));
		}
	}

	solve(board, emptys);
	return 0;
}
