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
		std::string str;
		std::cin >> str;

		int score_sum = 0;
		int bonus = 0;
		for (int j = 0; j < str.size(); ++j)
		{
			if (str[j] == 'O')
			{
				++bonus;
				score_sum += bonus;
			}
			else
				bonus = 0;
		}
		std::cout << score_sum << '\n';
	}
	return 0;
}
