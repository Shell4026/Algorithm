#include <iostream>
#include <vector>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> v;
	v.resize(n, 0);
	for (int i = 0; i < m; ++i)
	{
		int start, end, ball;
		std::cin >> start >> end >> ball;
		for (int j = start - 1; j < end; ++j)
		{
			v[j] = ball;
		}
	}
	for (auto i : v)
	{
		std::cout << i << ' ';
	}
	return 0;
}
