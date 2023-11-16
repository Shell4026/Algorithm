#include <iostream>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		std::cout << a + b << '\n';
	}
	return 0;
}
