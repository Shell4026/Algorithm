#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>

struct Data
{
    int x, y, z, day;
};
int main()
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int m, n, h;
    std::cin >> m >> n >> h;
    std::vector<std::vector<std::vector<int>>> box;
    std::vector<std::vector<std::vector<bool>>> visited;
    box.resize(h, std::vector<std::vector<int>>(n, std::vector<int>(m, 0)));
    visited.resize(h, std::vector<std::vector<bool>>(n, std::vector<bool>(m, false)));

    int zeroTomatoCount = 0;
    std::queue<Data> q;

    for (int z = 0; z < h; ++z)
    {
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < m; ++x)
            {
                std::cin >> box[z][y][x];
                if (box[z][y][x] == 1)
                {
                    q.push({ x, y, z, 0 });
                    visited[z][y][x] = true;
                }
                else if (box[z][y][x] == 0)
                    zeroTomatoCount++;
                else
                    visited[z][y][x] = true;
            }
        }
    }

    int finalDay = 0;
    while (!q.empty())
    {
        auto [x, y, z, day] = q.front();
        q.pop();
        if (day > finalDay)
            finalDay = day;

        static constexpr int DX[6] = { -1, 0, 1, 0, 0, 0 };
        static constexpr int DY[6] = { 0, 1, 0, -1, 0, 0 };
        static constexpr int DZ[6] = { 0, 0, 0, 0, 1, -1 };

        for (int i = 0; i < 6; ++i)
        {
            int dx = DX[i] + x;
            int dy = DY[i] + y;
            int dz = DZ[i] + z;
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && dz >= 0 && dz < h)
            {
                if (visited[dz][dy][dx])
                    continue;

                visited[dz][dy][dx] = true;
                q.push({ dx, dy, dz, day + 1 });
                zeroTomatoCount--;
            }
        }
    }

    if (zeroTomatoCount <= 0)
        std::cout << finalDay;
    else
        std::cout << -1;
    return 0;
}
