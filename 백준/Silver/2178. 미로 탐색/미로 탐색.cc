#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

constexpr int DX[4] = { -1, 0, 1, 0 };
constexpr int DY[4] = { 0, 1, 0, -1 };

struct Pos
{
    int x, y;
};

int main()
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> map;
    std::vector<std::vector<int>> dis;
    std::vector<std::vector<bool>> visited;

    map.resize(n, std::vector<int>(m, 0));
    dis.resize(n, std::vector<int>(m, 1));
    visited.resize(n, std::vector<bool>(m, false));

    for (int i = 0; i < n; ++i)
    {
        std::string line;
        std::cin >> line;
        for (int j = 0; j < m; ++j)
        {
            map[i][j] = line[j] - '0';
        }
    }

    std::queue<Pos> q;
    q.push(Pos{ 0, 0 });
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dx = DX[i] + x;
            int dy = DY[i] + y;
            if (!(dx >= 0 && dx < m && dy >= 0 && dy < n))
                continue;
            if (map[dy][dx] == 0)
                continue;
            if (visited[dy][dx])
                continue;
            visited[dy][dx] = true;
            dis[dy][dx] = dis[y][x] + 1;
            q.push(Pos{ dx, dy });
        }
    }
    std::cout << dis[n - 1][m - 1] << '\n';
    return 0;
}
