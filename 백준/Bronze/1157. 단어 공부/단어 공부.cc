#include <iostream>
#include <string>
#include <algorithm>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string str;
	std::cin >> str;

	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
	
	if (str.size() == 1)
	{
		std::cout << str;
		return 0;
	}
	int count[26] = { 0, };
	for (auto c : str)
	{
		++count[c - 65];
	}
	int max = count[0];
	int idx = 0;
	for (int i = 1; i < 26; ++i)
	{
		if (count[i] > max)
		{
			max = count[i];
			idx = i;
		}
	}
	for (int i = 1; i < 26; ++i)
	{
		if (count[i] == 0)
			continue;
		if (count[i] == max && i != idx)
		{
			std::cout << '?';
			return 0;
		}
	}
	std::cout << (char)(idx + 65);
	return 0;
}
