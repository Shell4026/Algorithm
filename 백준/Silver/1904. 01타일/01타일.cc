#include <iostream>
#include <vector>

std::vector<int> mem(1000000, 0);

int solve(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (mem[n] > 0)
		return mem[n] % 15746;

	mem[n] = solve(n - 1) % 15746 + solve(n - 2) % 15746;
	return mem[n] % 15746;
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;
	std::cout << solve(n);
	return 0;
}
