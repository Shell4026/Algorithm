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
	
	uint64_t start = 1;
	uint64_t end = arr[n - 1] - arr[0];
	uint64_t result;

	uint64_t ans = 0;
	while (start <= end)
	{
		int cnt = 1;
		uint64_t mid = (start + end) / 2;
		int louterIdx = 0;

		for (int i = 1; i < arr.size(); ++i)
		{
			if (arr[i] - arr[louterIdx] >= mid)
			{
				++cnt;
				louterIdx = i;
			}
		}
		if (cnt >= m)
		{
			start = mid + 1;
			ans = std::max(ans, mid);
		}
		else
			end = mid - 1;
	}
	std::cout << ans << '\n';
}
