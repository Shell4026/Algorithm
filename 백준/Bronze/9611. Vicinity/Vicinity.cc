#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

struct Point
{
	int x, y;

	auto GetDistance(const Point& other) const -> float
	{
		int dx = x - other.x;
		int dy = y - other.y;
		return std::sqrt(dx * dx + dy * dy);
	}
};

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	
	std::vector<Point> points(n, Point{ 0, 0 });
	for (int i = 0; i < n; ++i)
		std::cin >> points[i].x >> points[i].y;

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int idx, d, cnt = 0;
		std::cin >> idx >> d;
		for (int j = 0; j < points.size(); ++j)
		{
			if (j == idx - 1)
				continue;

			float dis = points[idx - 1].GetDistance(points[j]);
			if (dis <= d)
				++cnt;
		}
		std::cout << cnt << '\n';
	}
}
