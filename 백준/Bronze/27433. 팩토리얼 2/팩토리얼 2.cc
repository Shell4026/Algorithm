#include <iostream>

long long answer(int n)
{
	if (n < 2)
		return 1;
	if (n == 2)
		return 2;
	return n * answer(n - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::cout << answer(n);
	return 0;
}
