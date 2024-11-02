#include <iostream>
#include <algorithm>
#include <array>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::array<int, 6> input{};
	for (int i = 0; i < 6; ++i)
		std::cin >> input[i];

	int t, p;
	std::cin >> t >> p;

	int resultT = 0;
	for (int i = 0; i < 6; ++i)
	{
		if (input[i] == 0)
			continue;
		resultT += input[i] / t + 1;
		if (input[i] % t == 0)
			resultT--;
	}
	std::cout << resultT << '\n';
	std::cout << n / p << ' ' << n % p;
	return 0;
}
