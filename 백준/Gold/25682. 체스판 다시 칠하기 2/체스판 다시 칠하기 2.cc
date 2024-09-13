#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

std::vector<std::vector<int>> sumBlack{};
std::vector<std::vector<int>> sumWhite{};

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int w, h, size;
	std::cin >> h >> w >> size;

	sumBlack.resize(h, std::vector<int>(w, 0));
	sumWhite.resize(h, std::vector<int>(w, 0));

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			char color;
			std::cin >> color;
			bool addBlack{ false };
			bool addWhite{ false };

			if ((x + y) % 2 == 0)
			{
				addBlack = color == 'W';
				addWhite = color == 'B';
			}
			else
			{
				addBlack = color == 'B';
				addWhite = color == 'W';
			}

			if (x == 0 && y == 0)
			{
				sumBlack[y][x] = addBlack;
				sumWhite[y][x] = addWhite;
			}
			else if (y == 0)
			{
				sumBlack[y][x] = addBlack + sumBlack[y][x - 1];
				sumWhite[y][x] = addWhite + sumWhite[y][x - 1];
			}
			else if (x == 0)
			{
				sumBlack[y][x] = addBlack + sumBlack[y - 1][x];
				sumWhite[y][x] = addWhite + sumWhite[y - 1][x];
			}
			else
			{
				sumBlack[y][x] = addBlack + sumBlack[y][x - 1] + sumBlack[y - 1][x] - sumBlack[y - 1][x - 1];
				sumWhite[y][x] = addWhite + sumWhite[y][x - 1] + sumWhite[y - 1][x] - sumWhite[y - 1][x - 1];
			}
		}
	}

	int min{ size * size };
	for (int y1 = 0; y1 < h - size + 1; ++y1)
	{
		for (int x1 = 0; x1 < w - size + 1; ++x1)
		{
			int x2 = x1 + size - 1;
			int y2 = y1 + size - 1;

			int value1{ 0 };
			int value2{ 0 };
			if (x1 == 0 && y1 == 0)
			{
				value1 = sumBlack[y2][x2];
				value2 = sumWhite[y2][x2];
			}
			else if (x1 == 0)
			{
				value1 = sumBlack[y2][x2] - sumBlack[y1 - 1][x2];
				value2 = sumWhite[y2][x2] - sumWhite[y1 - 1][x2];
			}
			else if (y1 == 0)
			{
				value1 = sumBlack[y2][x2] - sumBlack[y2][x1 - 1];
				value2 = sumWhite[y2][x2] - sumWhite[y2][x1 - 1];
			}
			else
			{
				value1 = sumBlack[y2][x2] - sumBlack[y1 - 1][x2] - sumBlack[y2][x1 - 1] + sumBlack[y1 - 1][x1 - 1];
				value2 = sumWhite[y2][x2] - sumWhite[y1 - 1][x2] - sumWhite[y2][x1 - 1] + sumWhite[y1 - 1][x1 - 1];
			}

			min = std::min({ min, value1, value2 });
		}
	}

	std::cout << min;
	return 0;
}
