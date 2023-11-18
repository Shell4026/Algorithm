#include <iostream>
#include <string>
#include <set>

struct MyCompare
{
	bool operator()(const std::string& left, const std::string& right) const
	{
		if (left.size() == right.size())
			return left < right;
		return left.size() < right.size();
	}
};

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::set<std::string, MyCompare> strs;
	for (int i = 0; i < n; ++i)
	{
		std::string str;
		std::cin >> str;
		strs.insert(str);
	}
	for (auto& i : strs)
	{
		std::cout << i << '\n';
	}
	return 0;
}
