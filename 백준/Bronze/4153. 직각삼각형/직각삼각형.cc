#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	while (true)
	{
		std::array<int, 3> input;
		std::cin >> input[0] >> input[1] >> input[2];
		if (input[0] == 0 && input[1] == 0 && input[2] == 0)
			break;

		int max = *std::max_element(input.begin(), input.end());
		int sum = 0;
		for (int i = 0; i < 3; ++i)
		{
			if (input[i] == max)
				continue;
			sum += input[i] * input[i];
		}
		if (sum == max * max)
			std::cout << "right\n";
		else
			std::cout << "wrong\n";
	}
	return 0;
}
