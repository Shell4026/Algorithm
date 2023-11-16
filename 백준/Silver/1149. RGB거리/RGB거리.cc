#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
int solve(std::array<int, 3> &mem, std::vector<std::array<int, 3>> &costs, int n)
{
	mem[0] = costs[0][0];
	mem[1] = costs[0][1];
	mem[2] = costs[0][2];
	for (int i = 1; i < n; ++i)
	{
		int m0 = mem[0];
		int m1 = mem[1];
		int m2 = mem[2];
		mem[0] = std::min(m1 + costs[i][0], m2 + costs[i][0]);
		mem[1] = std::min(m0 + costs[i][1], m2 + costs[i][1]);
		mem[2] = std::min(m0 + costs[i][2], m1 + costs[i][2]);
	}
	return *std::min_element(mem.begin(), mem.end());
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::array<int, 3> mem_min{};
	std::vector<std::array<int, 3>> costs(n, std::array<int, 3>{});
	for (int i = 0; i < n; ++i)
	{
		int r, g, b;
		std::cin >> r >> g >> b;
		costs[i][0] = r;
		costs[i][1] = g;
		costs[i][2] = b;
	}
	std::cout << solve(mem_min, costs, n) << '\n';
	return 0;
}
