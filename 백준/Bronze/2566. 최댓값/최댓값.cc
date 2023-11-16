#include <iostream>
#include <array>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::array<std::array<int, 9>, 9> arr = {{0,},};
	
	int max = 0;
	int max_col = 0;
	int max_row = 0;
	for (int col = 0; col < 9; ++col)
	{
		for (int row = 0; row < 9; ++row)
		{
			std::cin >> arr[col][row];
			if (arr[col][row] > max)
			{
				max = arr[col][row];
				max_col = col;
				max_row = row;
			}
		}
	}
	std::cout << max << '\n';
	std::cout << max_col + 1 << ' ' << max_row + 1;
	return 0;
}
