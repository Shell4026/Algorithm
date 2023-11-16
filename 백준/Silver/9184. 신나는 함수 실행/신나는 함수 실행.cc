#include <iostream>
#include <array>

std::array<std::array<std::array<int, 21>, 21>, 21> mem = {};

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
		
	if (mem[a][b][c] > 0)
		return mem[a][b][c];

	if (a < b && b < c)
	{
		mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return mem[a][b][c];
	}
	mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return mem[a][b][c];
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	while (true)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		std::cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
	return 0;
}
