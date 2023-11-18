#include <iostream>
#include <string>
#include <array>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int a, b, c;
	std::cin >> a >> b >> c;

	std::string str = std::to_string(a * b * c);
	std::array<int, 10> cnt{};

	for (auto i : str)
	{
		++cnt[i - '0'];
	}
	for (auto i : cnt)
	{
		std::cout << i << '\n';
	}
	return 0;
}
