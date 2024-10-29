#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];
	std::sort(arr.begin(), arr.end());
	
	uint64_t start = 0;
	uint64_t end = arr[n - 1];
	uint64_t result;
	while (start <= end)
	{
		uint64_t mid = (start + end) / 2;
		uint64_t sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] <= mid)
				continue;

			sum += arr[i] - mid;
		}

		if (sum >= m)
		{
			result = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	std::cout << result << '\n';
}
