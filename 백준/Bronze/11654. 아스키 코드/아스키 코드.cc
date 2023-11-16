#include <iostream>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	char c;
	std::cin >> c;
	std::cout << (int)c;
	return 0;
}
