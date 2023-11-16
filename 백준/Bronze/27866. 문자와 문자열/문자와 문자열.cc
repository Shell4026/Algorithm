#include <iostream>
#include <string>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::string str;
	std::cin >> str;

	int idx;
	std::cin >> idx;

	std::cout << str[idx - 1];
	return 0;
}
