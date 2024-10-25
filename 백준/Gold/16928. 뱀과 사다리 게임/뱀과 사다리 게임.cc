#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>

int main()
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int ladder, snake;
    std::cin >> ladder >> snake;

    std::array<int, 100> move;
    for (int i = 0; i < 100; ++i)
        move[i] = i;

    for (int i = 0; i < ladder; ++i)
    {
        int start, end;
        std::cin >> start >> end;
        move[start - 1] = end - 1;
    }
    for (int i = 0; i < snake; ++i)
    {
        int start, end;
        std::cin >> start >> end;
        move[start - 1] = end - 1;
    }

    std::array<bool, 100> visited;
    std::array<int, 100> dis;
    visited.fill(false);
    dis.fill(0);

    std::queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int id = q.front();
        q.pop();

        if (id == 99)
        {
            std::cout << dis[id];
            break;
        }

        for (int dice = 1; dice <= 6; ++dice)
        {
            int next = id + dice;
            if (next >= 100)
                continue;

            int finalPos = move[next];

            if (visited[finalPos])
                continue;

            visited[finalPos] = true;
            dis[finalPos] = dis[id] + 1;
            q.push(finalPos);
        }
    }
    return 0;
}
