#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

std::string str{};
std::array<std::vector<int>, 26> dp{};

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	std::cin >> str;

	int n = 0;
	std::cin >> n;

	std::size_t size = str.size();
	for (int i = 0; i < 26; ++i)
		dp[i].resize(size, 0);

	for (int i = 0; i < size; ++i)
	{
		char c = str[i];
		if (i > 0)
			for(int j = 0; j < 26; ++j)
				dp[j][i] = dp[j][i - 1];

		++dp[c - 'a'][i];
	}

	for (int i = 0; i < n; ++i)
	{
		char c;
		int start, end;
		std::cin >> c >> start >> end;

		if (start - 1 >= 0)
			std::cout << dp[c - 'a'][end] - dp[c - 'a'][start - 1] << '\n';
		else
			std::cout << dp[c - 'a'][end] << '\n';
	}

	return 0;
}