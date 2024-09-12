#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

std::string str{};
std::array<std::vector<int>, 26> dp;

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> str;

	int n = 0;
	std::cin >> n;

	for (int i = 0; i < 26; ++i)
		dp[i].resize(str.size(), -1);

	for (int i = 0; i < n; ++i)
	{
		char c;
		int start, end;
		std::cin >> c >> start >> end;

		if (start - 1 >= 0)
			if (dp[c - 'a'][start - 1] == -1)
				dp[c - 'a'][start - 1] = std::count(str.begin(), str.begin() + start, c);
		if (dp[c - 'a'][end] == -1)
			dp[c - 'a'][end] = std::count(str.begin(), str.begin() + end + 1, c);
			
		if (start - 1 < 0)
			std::cout << dp[c - 'a'][end] << '\n';
		else
			std::cout << dp[c - 'a'][end] - dp[c - 'a'][start - 1] << '\n';
	}

	return 0;
}