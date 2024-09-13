#include <iostream>
#include <vector>
#include <array>

typedef std::array<std::array<bool, 8>, 8> Board;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	int col_cnt = n - 8 + 1;
	int row_cnt = m - 8 + 1;
	int cnt = col_cnt * row_cnt;

	Board board{ std::array<bool, 8>{false} };
	std::vector<Board> boards(cnt, board);

	std::vector<bool> col(m);
	std::vector<std::vector<bool>> input(n, col);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char c;
			std::cin >> c;
			input[i][j] = c == 'W' ? 1 : 0;
		}
	}
	for (int c = 0; c < col_cnt; ++c)
	{
		for (int r = 0; r < row_cnt; ++r)
		{
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					boards[c * row_cnt + r][i][j] = input[i + c][j + r];
				}
			}
		}
	}
	int min = 64;
	for (int c = 0; c < cnt; ++c)
	{
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (i % 2 == 0 && j % 2 == 0 || i % 2 == 1 && j % 2 == 1)
				{
					if (boards[c][i][j] != boards[c][0][0])
						++cnt1;
					if (boards[c][i][j] != !boards[c][0][0])
						++cnt2;
				}
				else
				{
					if (boards[c][i][j] != !boards[c][0][0])
						++cnt1;
					if (boards[c][i][j] != boards[c][0][0])
						++cnt2;
				}
			}
		}
		if (cnt1 < min)
			min = cnt1;
		if (cnt2 < min)
			min = cnt2;
	}
	std::cout << min;
	return 0;
}
