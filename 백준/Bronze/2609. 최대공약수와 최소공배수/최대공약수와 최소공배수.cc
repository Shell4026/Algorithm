#include <iostream>
#include <algorithm>
#include <array>

int GCD(int a, int b)
{
	if (b > a)
		std::swap(a, b);
	while (b != 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int LCM(int a, int b, int gcd)
{
	int p = a / gcd;
	int q = b / gcd;
	return gcd * p * q;
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int a, b;
	std::cin >> a >> b;

	int gcd = GCD(a, b);
	std::cout << gcd << '\n' << LCM(a, b, gcd);
}
