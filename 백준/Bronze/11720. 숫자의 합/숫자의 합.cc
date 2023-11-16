#include <iostream>
#include <string>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::string str;
	std::cin >> n >> str;

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += str[i] - 48;
	}
	std::cout << sum;
	return 0;
}
