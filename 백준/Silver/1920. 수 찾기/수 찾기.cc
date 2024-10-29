#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n;
	std::vector<int> input(n, 0);
	for (int i = 0; i < n; ++i)
		std::cin >> input[i];

	std::sort(input.begin(), input.end());

	std::cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int num;
		std::cin >> num;
		std::cout << std::binary_search(input.begin(), input.end(), num) << '\n';
	}
	return 0;
}
