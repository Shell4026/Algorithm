#include <iostream>
#include <string>
#include <array>
int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::string str;
	std::cin >> str;

	std::array<int, 26> arr{};
	arr.fill(-1);
	for (int i = 0; i < str.size(); ++i)
	{
		int idx = str[i] - 'a';
		if (arr[idx] == -1)
		{
			arr[idx] = i;
		}
	}
	for (auto i : arr)
	{
		std::cout << i << '\n';
	}
	return 0;
}
