#include <iostream>
#include <algorithm>
#include <array>

auto Factorial(int n) -> int
{
	if (n == 0)
		return 1;
	int result = n;
	for (int i = n - 1; i > 1; --i)
		result *= i;
	return result;
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	int result = 0;
	if (k >= 0 && k <= n)
	{
		result = Factorial(n) / (Factorial(k) * Factorial(n - k));
	}
	std::cout << result << '\n';
}
