#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	constexpr uint8_t BLACK = 1;
	constexpr uint8_t WHITE = 2;

	int k;
	std::cin >> k;
	for (int i = 0; i < k; ++i)
	{
		int v, e;
		std::cin >> v >> e;
		std::vector<std::vector<int>> graph(v, std::vector<int>());
		std::vector<uint8_t> visited(v, false);
		for (int j = 0; j < e; ++j)
		{
			int v1, v2;
			std::cin >> v1 >> v2;
			graph[v1 - 1].push_back(v2 - 1);
			graph[v2 - 1].push_back(v1 - 1);
		}
		std::queue<int> q;

		auto checkFn = [&]() -> bool
		{
			for (int i = 0; i < v; ++i)
			{
				if (visited[i])
					continue;

				q.push(i);
				visited[i] = WHITE;

				while (!q.empty())
				{
					int v = q.front();
					q.pop();

					uint8_t currentColor = 2 - (visited[v] - 1); // 현재 노드와 다른 색
					for (auto v2 : graph[v])
					{
						if (visited[v2] == visited[v])
							return false;
						if (visited[v2])
							continue;

						visited[v2] = currentColor;
						q.push(v2);
					}
				}
			}
			return true;
		};
		if (checkFn())
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}

	return 0;
}
