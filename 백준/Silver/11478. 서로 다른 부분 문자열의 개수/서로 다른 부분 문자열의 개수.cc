#include <iostream>
#include <set>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string str;
	std::cin >> str;
	
	std::set<std::string> sub;
	for (int i = 0; i < str.size(); ++i)
	{
		for (int j = 0; j < str.size() - i; ++j)
		{
			sub.insert(str.substr(j, i + 1));
		}
	}
	std::cout << sub.size();
}
