#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>

struct Pos
{
    int x, y;
};
int main()
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int t, size;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int startX, startY;
        int endX, endY;
        std::cin >> size;
        std::cin >> startX >> startY;
        std::cin >> endX >> endY;

        std::vector<std::vector<int>> dis(size, std::vector<int>(size, 0));
        std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));

        std::queue<Pos> q;
        q.push({ startX, startY });
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (x == endX && y == endY)
            {
                std::cout << dis[y][x] << '\n';
                break;
            }

            static constexpr int DX[8] = { 1,2,2,1,-1,-2,-2,-1 };
            static constexpr int DY[8] = { 2,1,-1,-2,-2,-1,1,2 };
            for (int i = 0; i < 8; ++i)
            {
                int dx = DX[i] + x;
                int dy = DY[i] + y;
                if (dx >= 0 && dx < size && dy >= 0 && dy < size)
                {
                    if (visited[dy][dx])
                        continue;
                    q.push({ dx,dy });
                    visited[dy][dx] = true;
                    dis[dy][dx] = dis[y][x] + 1;
                }
            }
        }
    }


    return 0;
}
