#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

void VectorShift(std::vector<int>& v, std::size_t pos, std::size_t to)
{
	int posInt = v[pos];
	for (int i = pos; i > to; --i)
	{
		v[i] = v[i - 1];
	}
	v[to] = posInt;
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> input(n, 0);
	for (int i = 0; i < n; ++i)
		std::cin >> input[i];
	int s;
	std::cin >> s;

	for (int i = 0; i < n; ++i)
	{
		if (s == 0)
			break;

		auto end = input.end();
		if (i + s + 1 <= n)
			end = input.begin() + i + s + 1;
		auto it = std::max_element(input.begin() + i, end);
		int idx = std::distance(input.begin(), it);
		if (idx == i)
			continue;

		VectorShift(input, idx, i);
		s -= idx - i;
	}

	for (auto i : input)
		std::cout << i << ' ';
	return 0;
}
