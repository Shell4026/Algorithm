#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_map>

std::vector<int> input{};
std::vector<uint64_t> mem{};
std::array<uint64_t, 1000> divMem;

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n, div;
	std::cin >> n >> div;

	input.resize(n, 0);
	mem.resize(n, 0);

	uint64_t cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> input[i];
		mem[i] = input[i];
		if(i > 0)
			mem[i] += mem[i - 1];

		int _div = mem[i] % div;
		if (_div == 0)
			++cnt;

		++divMem[_div];
	}

	for (auto n : divMem)
	{
		cnt += n * (n - 1) / 2;
	}

	std::cout << cnt;
	return 0;
}