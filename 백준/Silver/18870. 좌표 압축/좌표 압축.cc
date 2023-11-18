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

	std::vector<int> arr(n, 0);
	std::vector<int> original(n, 0);
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		arr[i] = num;
		original[i] = num;
	}
	std::sort(arr.begin(), arr.end());
	arr.erase(std::unique(arr.begin(), arr.end()), arr.end());

	for (auto i : original)
	{
		std::cout << std::lower_bound(arr.begin(), arr.end(), i) - arr.begin() << ' ';
	}
	return 0;
}
