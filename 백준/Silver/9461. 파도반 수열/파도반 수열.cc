#include <iostream>
#include <array>

long long solve(std::array<long long, 97>& mem, int n)
{
	if (n == 1 || n == 2 || n == 3)
		return 1;
	if (mem[n - 4] > 0)
		return mem[n - 4];

	mem[n - 4] = solve(mem, n - 2) + solve(mem, n - 3);
	return mem[n - 4];
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::array<long long, 97> mem{};
	
	int cnt;
	std::cin >> cnt;

	for (int i = 0; i < cnt; ++i)
	{
		int n;
		std::cin >> n;
		std::cout << solve(mem, n) << '\n';
	}
	return 0;
}
