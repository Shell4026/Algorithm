#include <iostream>
#include <algorithm>
#include <vector>

int solve(std::vector<int>&mem, int n)
{
	if (n == 1)
		return 0;
	if (n == 2 || n == 3)
		return 1;
	if (mem[n] > 0)
		return mem[n];

	if (n % 3 == 0 && n % 2 == 0)
	{
		int a, b;

		if (mem[n / 3] == 0)
			mem[n / 3] = solve(mem, n / 3);
		a = mem[n / 3];

		if (mem[n / 2] == 0)
			mem[n / 2] = solve(mem, n / 2);
		b = mem[n / 2];

		return std::min(a, b) + 1;
	}
		
	if (n % 3 == 0)
	{
		int a, b;

		if (mem[n / 3] == 0)
			mem[n / 3] = solve(mem, n / 3);
		a = mem[n / 3];

		if (mem[n - 1] == 0)
			mem[n - 1] = solve(mem, n - 1);
		b = mem[n - 1];

		return std::min(a, b) + 1;
	}
	if (n % 2 == 0)
	{
		int a, b;

		if (mem[n / 2] == 0)
			mem[n / 2] = solve(mem, n / 2);
		a = mem[n / 2];

		if (mem[n - 1] == 0)
			mem[n - 1] = solve(mem, n - 1);
		b = mem[n - 1];

		return std::min(a, b) + 1;
	}
	if (mem[n - 1] == 0)
		mem[n - 1] = solve(mem, n - 1);
	return mem[n - 1] + 1;
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> mem(n + 1, 0);
	std::cout << solve(mem, n);
	return 0;
}
