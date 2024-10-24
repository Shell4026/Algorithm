#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph;
std::vector<bool> visit;
int cnt = 0;

void DFS(int v)
{
    if (visit[v])
        return;
    visit[v] = true;
    ++cnt;
    for(auto e : graph[v])
        DFS(e);
}

int main() 
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

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

    DFS(0);

    std::cout << cnt - 1 << '\n';
    
    return 0;
}
