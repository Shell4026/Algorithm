#include <iostream>
#include <string>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int repeat;
		std::string str;
		std::cin >> repeat >> str;
		for (auto c : str)
		{
			for (int r = 0; r < repeat; ++r)
				std::cout << c;
		}
		std::cout << '\n';
	}
	return 0;
}
