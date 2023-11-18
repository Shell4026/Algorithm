#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::set<int> set;
	std::vector<int> original(n, 0);
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		set.insert(num);
		original[i] = num;
	}
	std::vector<int> arr(set.size(), 0);
	auto it = set.begin();
	for (int i = 0; i < set.size(); ++i)
	{
		arr[i] = *it++;
	}

	for (auto i : original)
	{
		std::cout << std::lower_bound(arr.begin(), arr.end(), i) - arr.begin() << ' ';
	}
	return 0;
}
