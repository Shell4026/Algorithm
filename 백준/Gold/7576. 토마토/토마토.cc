#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>

struct Data
{
    int x, y, day;
};
int main()
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> box;
    std::vector<std::vector<bool>> visited;
    box.resize(n, std::vector<int>(m, 0));
    visited.resize(n, std::vector<bool>(m, false));

    int zeroTomatoCount = 0;
    std::queue<Data> q;

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            std::cin >> box[y][x];
            if (box[y][x] == 1)
            {
                q.push({ x, y, 0 });
                visited[y][x] = true;
            }
            else if (box[y][x] == 0)
                zeroTomatoCount++;
            else
                visited[y][x] = true;
        }
    }

    int finalDay = 0;
    while (!q.empty())
    {
        auto [x, y, day] = q.front();
        q.pop();
        if (day > finalDay)
            finalDay = day;

        static constexpr int DX[4] = { -1, 0, 1, 0 };
        static constexpr int DY[4] = { 0, 1, 0, -1 };

        for (int i = 0; i < 4; ++i)
        {
            int dx = DX[i] + x;
            int dy = DY[i] + y;
            if (dx >= 0 && dx < m && dy >= 0 && dy < n)
            {
                if (visited[dy][dx])
                    continue;

                visited[dy][dx] = true;
                q.push({ dx, dy, day + 1 });
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
