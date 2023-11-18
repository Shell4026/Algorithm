#include <iostream>
#include <string>

int solve(std::string& str)
{
	bool start = false;
	int count = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] != ' ')
			start = true;
		else
		{
			if (start)
			{
				start = false;
				++count;
			}
		}
		if (i + 1 == str.size())
		{
			if (start)
				++count;
		}
	}
	return count;
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::string str;
	std::getline(std::cin, str);

	std::cout << solve(str);
	return 0;
}
