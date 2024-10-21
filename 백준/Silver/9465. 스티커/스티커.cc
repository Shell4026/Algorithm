#include <iostream>

#include <array>
#include <vector>
#include <algorithm>

std::array<std::vector<uint32_t>, 2> scores{};
std::array<std::vector<uint32_t>, 2> dp{};

constexpr bool UP = false;
constexpr bool DOWN = true;

void Solve(bool pos, std::size_t n)
{
    if (n == 0)
    {
        dp[pos][n] = scores[pos][n];
        return;
    }
    if (n == 1)
    {
        if (dp[!pos][0] == -1)
            Solve(!pos, 0);
        dp[pos][1] = dp[!pos][0] + scores[pos][1];
        return;
    }
    if (dp[!pos][n - 1] == -1)
        Solve(!pos, n - 1);
    if (dp[pos][n - 2] == -1)
        Solve(pos, n - 2);
    if (dp[!pos][n - 2] == -1)
        Solve(!pos, n - 2);

    dp[pos][n] = std::max(dp[!pos][n - 1] + scores[pos][n], std::max(dp[pos][n - 2], dp[!pos][n - 2]) + scores[pos][n]);
}

int main() 
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int caseCnt;
    std::cin >> caseCnt;

    for (int i = 0; i < caseCnt; ++i)
    {
        int n;
        std::cin >> n;

        for (int idx = 0; idx < 2; ++idx)
        {
            scores[idx].clear();
            scores[idx].resize(n, 0);
            dp[idx].clear();
            dp[idx].resize(n, -1);
            for (int j = 0; j < n; ++j)
                std::cin >> scores[idx][j];
        }
        
        Solve(UP, n - 1);
        Solve(DOWN, n - 1);
        std::cout << std::max(dp[UP][n - 1], dp[DOWN][n - 1]) << '\n';
    }
    return 0;
}
