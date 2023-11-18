#include <iostream>
#include <string>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	while (true)
	{
		std::string str;
		std::cin >> str;
		if (str == "0")
			break;

		for (int i = 0; i < str.size(); ++i)
		{
			int first = i;
			int end = str.size() - i - 1;
			if (first >= end)
			{
				std::cout << "yes\n";
				break;
			}
			if (str[first] != str[end])
			{
				std::cout << "no\n";
				break;
			}
		}
	}
	return 0;
}
