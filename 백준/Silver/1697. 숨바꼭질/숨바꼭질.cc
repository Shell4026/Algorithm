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

    int n, k;
    std::cin >> n >> k;

    std::array<int, 100'001> dis;
    std::array<int, 100'001> visited;

    dis.fill(0);
    visited.fill(false);

    std::queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == k)
        {
            std::cout << dis[x] << '\n';
            break;
        }

        auto Visit = [&](int next, int x)
        {
            if (!visited[next])
            {
                dis[next] = dis[x] + 1;
                q.push(next);
                visited[next] = true;
            }
        };
        if (x + 1 < 100'001)
        {
            Visit(x + 1, x);
        }
        if (x - 1 >= 0)
        {
            Visit(x - 1, x);
        }
        if (x * 2 < 100'001)
        {
            Visit(x * 2, x);
        }
    }

    return 0;
}
