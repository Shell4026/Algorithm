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
    ++cnt;
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

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    graph.resize(n * n, std::vector<int>());
    visit.resize(n * n, false);

    for (int y = 0; y < n; ++y)
    {
        std::string line;
        std::cin >> line;
        for (int x = 0; x < n; ++x)
        {
            board[y][x] = line[x] - '0';
            int id = x + n * y;
            if (board[y][x] == 0)
                continue;
            if (x > 0)
            {
                if (board[y][x - 1] == 1)
                {
                    graph[id - 1].push_back(id);
                    graph[id].push_back(id - 1);
                }
            }
            if (y > 0)
            {
                if (board[y - 1][x] == 1)
                {
                    graph[id - n].push_back(id);
                    graph[id].push_back(id - n);
                }
            }
        }
    }

    int complex = 0;
    std::vector<int> cnts;
    for (int i = 0; i < n * n; ++i)
    {
        if (board[i / n][i % n] == 0)
            continue;
        if (visit[i])
            continue;
        DFS(i);
        ++complex;
        cnts.push_back(cnt);
        cnt = 0;
    }
    std::sort(cnts.begin(), cnts.end());
    std::cout << complex << '\n';
    for (auto c : cnts)
        std::cout << c << '\n';
    return 0;
}
