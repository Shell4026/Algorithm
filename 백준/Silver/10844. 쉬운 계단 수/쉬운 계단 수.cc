#include <iostream>
#include <vector>

int solve(std::vector<std::vector<int>>& mem, int n, int m)
{
    if (n == 1)
    {
        return 1;
    }
    if (m + 1 < 10)
    {
        if (m == 0)
        {
            if (mem[n - 1][m + 1] == 0)
                mem[n - 1][m + 1] = solve(mem, n - 1, m + 1);

            return mem[n - 1][m + 1];
        }

        if (mem[n - 1][m - 1] == 0)
            mem[n - 1][m - 1] = solve(mem, n - 1, m - 1);

        if (mem[n - 1][m + 1] == 0)
            mem[n - 1][m + 1] = solve(mem, n - 1, m + 1);

        return mem[n - 1][m - 1] % 1000000000 + mem[n - 1][m + 1] % 1000000000;
    }
    else
    {
        if (mem[n - 1][m - 1] == 0)
            mem[n - 1][m - 1] = solve(mem, n - 1, m - 1);
        return  mem[n - 1][m - 1];
    }
}

int main()
{
    std::cout.tie(0)->sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> mem(n + 1, std::vector<int>(10, 0));

    int sum = 0;
    for (int i = 1; i <= 9; ++i)
    {
        sum += solve(mem, n, i) % 1000000000;
        sum %= 1000000000;
    }
    std::cout << sum;

    return 0;
}
