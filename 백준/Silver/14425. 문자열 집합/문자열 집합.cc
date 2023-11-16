#include <iostream>
#include <unordered_set>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::unordered_set<std::string> strs;

	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		std::string str;
		std::cin >> str;
		strs.insert(str);
	}

	int cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		std::string str;
		std::cin >> str;
		if (strs.find(str) != strs.end())
			++cnt;
	}
	std::cout << cnt;
	return 0;
}
