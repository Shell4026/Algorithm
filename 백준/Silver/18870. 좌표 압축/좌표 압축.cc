#include <iostream>
#include <vector>
#include <map>
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
		std::cin >> arr[i];

	original = arr;
	std::sort(arr.begin(), arr.end());
	std::map<int, int> comp;
	
	for (int i = 0, cnt = 0; i < arr.size(); ++i)
	{
		if (comp.find(arr[i]) == comp.end())
		{
			comp.insert({arr[i], cnt++});
		}
	}
	for (auto i : original)
	{
		std::cout << comp[i] << ' ';
	}
	return 0;
}
