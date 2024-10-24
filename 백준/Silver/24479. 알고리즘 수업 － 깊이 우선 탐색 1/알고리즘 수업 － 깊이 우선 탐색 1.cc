#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph;
std::vector<int> visit;
int order = 1;

void DFS(int v)
{
    visit[v] = order++;
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
        std::sort(e.begin(), e.end());

    DFS(r - 1);

    for (int i = 0; i < n; ++i)
    {
        std::cout << visit[i] << '\n';
    }

    return 0;
}
