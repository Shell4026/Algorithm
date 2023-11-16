#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> v;
	v.resize(n, 0);
	for (int i = 0; i < v.size(); ++i)
		v[i] = i + 1;
	for (int i = 0; i < m; ++i)
	{
		int start, end;
		std::cin >> start >> end;
		--start;

		std::reverse(v.begin() + start, v.begin() + end);

	}
	for (auto i : v)
	{
		std::cout << i << ' ';
	}
	return 0;
}
