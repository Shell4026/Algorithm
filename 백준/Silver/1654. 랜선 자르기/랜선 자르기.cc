#include <iostream>
#include <vector>
#include <limits>

typedef long long i64;

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int k, n;
	std::cin >> k >> n;
	std::vector<int> arr(k, 0);

	i64 start = 1;
	i64 mid = 0;
	i64 end = std::numeric_limits<int>::min();
	for (int i = 0; i < k; ++i)
	{
		std::cin >> arr[i];
		if (arr[i] > end)
			end = arr[i];
	}
	
	int result = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int cnt = 0;
		for (auto i : arr)
			cnt += i / mid;
		
		if (cnt >= n)
		{
			start = mid + 1;
			if (result < mid)
				result = mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	std::cout << result;
	return 0;
}
