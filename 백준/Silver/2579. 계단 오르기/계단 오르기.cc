#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>

std::vector<std::vector<int>> dp(2, std::vector<int>{});
std::vector<int> score{};

int Solution(int n, bool oneStep)
{
    if (n == 0)
        return score[0];
    if (n == 1 && oneStep)
        return score[1];
    if (n == 1 && !oneStep)
        return score[0] + score[1];

    if (dp[false][n - 2] == -1)
        dp[false][n - 2] = Solution(n - 2, false);
    if (oneStep)
    {
        return dp[false][n - 2] + score[n];
    }
    else
    {
        if (dp[true][n - 1] == -1)
            dp[true][n - 1] = Solution(n - 1, true);
        return std::max(dp[true][n - 1], dp[false][n - 2]) + score[n];
    }
}


int main()
{
    int cnt = 0;
    std::cin >> cnt;
    dp[0].resize(cnt, -1);
    dp[1].resize(cnt, -1);

    score.resize(cnt);

    for (int i = 0; i < cnt; ++i)
    {
        std::cin >> score[i];
    }

    std::cout << Solution(cnt - 1, false);
}
