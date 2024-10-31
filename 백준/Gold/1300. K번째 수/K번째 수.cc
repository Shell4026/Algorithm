#include <iostream>
#include <algorithm>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;
	
	int start = 1;
	int end = k;
	int ans = 0;
	
	while (end >= start)
	{
		int mid = (end + start) / 2;

		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			cnt += std::min(mid / i, n);

		if (cnt >= k)
		{
			ans = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	std::cout << ans << '\n';
}
