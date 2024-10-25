#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

std::vector<std::vector<int>> map;
std::vector<std::vector<bool>> visited;

constexpr int DX[4] = { -1, 0, 1, 0 };
constexpr int DY[4] = { 0, 1, 0, -1 };

int m, n;

void DFS(int x, int y)
{
    if (visited[y][x])
        return;

    visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int dx = DX[i] + x;
        int dy = DY[i] + y;
        if (dx >= 0 && dx < m && dy >= 0 && dy < n)
        {
            if (map[dy][dx] == 0)
                continue;
            DFS(dx, dy);
        }
    }
}

int main()
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int k;
        std::cin >> m >> n >> k;

        map.clear();
        map.resize(n, std::vector<int>(m, 0));
        visited.clear();
        visited.resize(n, std::vector<bool>(m, false));

        std::vector<std::pair<int, int>> pos;
        pos.resize(k, { 0, 0 });
        for (int j = 0; j < k; ++j)
        {
            int x, y;
            std::cin >> x >> y;
            map[y][x] = 1;
            pos[j] = { x , y };
        }

        int cnt = 0;
        for (auto& [x, y] : pos)
        {
            if (visited[y][x])
                continue;

            DFS(x, y);
            ++cnt;
        }
        std::cout << cnt << '\n';
    }

    return 0;
}
