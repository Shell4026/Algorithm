#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <string>
#include <limits>

int main()
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int v, e, k;
    std::cin >> v >> e >> k;

    using Dest = std::pair<int, int>; // 가중치, 정점
    std::vector<std::vector<Dest>> graph(v, std::vector<Dest>());

    for (int i = 0; i < e; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u - 1].push_back({ w, v - 1 });
    }

    std::vector<int> dis(v, std::numeric_limits<int>::max());
    std::priority_queue<Dest, std::vector<Dest>, std::greater<Dest>> pq;
    dis[k - 1] = 0;
    pq.push({ 0, k - 1 });

    while (!pq.empty())
    {
        auto [disMe, cur] = pq.top();
        pq.pop();
        if (dis[cur] != disMe)
            continue;
        for (auto& [disTo, to] : graph[cur])
        {
            int disSum = dis[cur] + disTo;
            if (disSum < dis[to])
            {
                dis[to] = disSum;
                pq.push({ disSum, to });
            }
        }
    }
    for (int d : dis)
    {
        if (d == std::numeric_limits<int>::max())
            std::cout << "INF\n";
        else
            std::cout << d << '\n';
    }
    return 0;
}
