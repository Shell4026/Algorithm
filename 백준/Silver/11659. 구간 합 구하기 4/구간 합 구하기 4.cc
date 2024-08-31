#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>

std::array<int, 100000> dp;

int main()
{
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nCnt = 0;
    int n = 0;
    std::cin >> nCnt >> n;

    for (int i = 0; i < nCnt; ++i)
    {
        std::cin >> dp[i];
        if(i != 0)
            dp[i] += dp[i - 1];
    }

    for (int i = 0; i < n; ++i)
    {
        int start, end;
        std::cin >> start >> end;

        if (start == 1)
            std::cout << dp[end - 1] << '\n';
        else
            std::cout << dp[end - 1] - dp[start - 2] << '\n';
    }
}