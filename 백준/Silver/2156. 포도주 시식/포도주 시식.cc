#include <iostream>
#include <vector>
#include <algorithm>

int solve(std::vector<int>& mem, std::vector<int>& wines, int n = 0)
{
    if (n == 0)
        return wines[0];
    if (n == 1)
        return wines[0] + wines[1];
    if (n == 2)
        return std::max({ wines[0] + wines[1], wines[0] + wines[2], wines[1] + wines[2] });

    if (mem[n - 1] == -1)
        mem[n - 1] = solve(mem, wines, n - 1);
    if (mem[n - 2] == -1)
        mem[n - 2] = solve(mem, wines, n - 2);
    if (mem[n - 3] == -1)
        mem[n - 3] = solve(mem, wines, n - 3);

    int case0 = mem[n - 1];
    int case1 = wines[n] + wines[n - 1] + mem[n - 3];
    int case2 = wines[n] + mem[n - 2];

    return std::max({ case0, case1, case2 });
}

int main()
{
    std::cout.tie(0)->sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> wines(n, 0);
    std::vector<int> mem(n - 1, -1);
    for (int i = 0; i < n; ++i)
        std::cin >> wines[i];

    std::cout << solve(mem, wines, n - 1);

    return 0;
}
