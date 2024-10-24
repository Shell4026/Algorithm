#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph;
std::vector<bool> visit;

void DFS(int v)
{
    std::cout << v + 1 << ' ';
    visit[v] = true;
    for (auto e : graph[v])
    {
        if (visit[e])
            continue;
        DFS(e);
    }
}


int main()
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, m, r;
    std::cin >> n >> m >> r;

    graph.resize(n, std::vector<int>());
    visit.resize(n, false);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (auto& e : graph)
        std::sort(e.begin(), e.end(), std::less());

    DFS(r - 1);
    std::cout << '\n';
    std::fill(visit.begin(), visit.end(), false);

    std::queue<int> order;
    order.push(r - 1);
    visit[r - 1] = true;

    while (!order.empty())
    {
        int v = order.front();
        order.pop();
        std::cout << v + 1 << ' ';

        for (auto e : graph[v])
        {
            if (visit[e])
                continue;
            visit[e] = true;
            order.push(e);
        }
    }
    std::cout << '\n';

    return 0;
}
