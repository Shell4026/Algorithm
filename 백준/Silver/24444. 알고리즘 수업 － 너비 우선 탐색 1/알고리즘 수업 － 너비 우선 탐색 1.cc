#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph;
std::vector<int> visit;

int main() 
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, m, r;
    std::cin >> n >> m >> r;

    graph.resize(n, std::vector<int>());
    visit.resize(n, 0);

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

    std::queue<int> order;
    order.push(r - 1);
    visit[r - 1] = 1;

    int nextOrder = 2;
    while (!order.empty())
    {
        int v = order.front();
        order.pop();

        for (auto e : graph[v])
        {
            if (visit[e])
                continue;
            visit[e] = nextOrder++;
            order.push(e);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << visit[i] << '\n';
    }

    return 0;
}
