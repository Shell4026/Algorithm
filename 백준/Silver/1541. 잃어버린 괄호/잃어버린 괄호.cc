#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	std::string str{};
	std::cin >> str;

	std::vector<int> nums{};

	std::string tmp{};
	int tmpSum{ 0 };
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '+')
		{
			tmpSum += std::stoi(tmp);
			tmp.clear();
			continue;
		}
		if (str[i] == '-')
		{
			tmpSum += std::stoi(tmp);
			tmp.clear();
			nums.push_back(tmpSum);
			tmpSum = 0;
			continue;
		}

		tmp += str[i];
	}
	tmpSum += std::stoi(tmp);
	nums.push_back(tmpSum);

	int result = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		result -= nums[i];
	}
	std::cout << result;
	return 0;
}