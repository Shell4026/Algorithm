#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <string>

struct Pos
{
    int x, y;
    bool broken;
};

std::vector<std::vector<int>> map{};
int n, m;

int main()
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    map.resize(n, std::vector<int>(m, 0));

    std::array<std::vector<std::vector<int>>, 2> dis;
    dis.fill(std::vector<std::vector<int>>(n, std::vector<int>(m, -1)));

    std::array<std::vector<std::vector<bool>>, 2> visited;
    visited.fill(std::vector<std::vector<bool>>(n, std::vector<bool>(m, false)));

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
    q.push({ 0, 0, false });
    dis[0][0][0] = 1;
    visited[0][0][0] = true;

    int minDis = -1;
    Pos minPos = { -1, -1 };
    while (!q.empty())
    {
        auto [x, y, broken] = q.front();
        q.pop();

        static constexpr int DX[4] = { -1, 0, 1, 0 };
        static constexpr int DY[4] = { 0, 1, 0, -1 };

        for (int i = 0; i < 4; ++i)
        {
            int dx = DX[i] + x;
            int dy = DY[i] + y;
            if (dx >= 0 && dx < m && dy >= 0 && dy < n)
            {
                if (visited[broken][dy][dx])
                    continue;
                dis[broken][dy][dx] = dis[broken][y][x] + 1;
                visited[broken][dy][dx] = true;
                if (map[dy][dx] == 1)
                {
                    if (!broken)
                    {
                        dis[true][dy][dx] = dis[broken][y][x] + 1;
                        visited[true][dy][dx] = true;
                        q.push({ dx,dy, true });
                    }
                    continue;
                }
                q.push({ dx, dy, broken });
            }
        }
    }
    int dis0 = dis[false][n - 1][m - 1];
    int dis1 = dis[true][n - 1][m - 1];
    if (dis0 == -1)
        std::cout << dis1;
    else if(dis1 == -1)
        std::cout << dis0;
    else
        std::cout << std::min(dis0, dis1);
    return 0;
}
