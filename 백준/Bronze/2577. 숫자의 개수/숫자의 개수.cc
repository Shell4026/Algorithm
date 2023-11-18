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

	int s = a * b * c;
	std::array<int, 10> arr{};
	while (s != 0)
	{
		++arr[s % 10];
		s /= 10;
	}
	for (auto i : arr)
		std::cout << i << '\n';
	return 0;
}
