#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>

std::vector<int> dp;
std::vector<int> path;

int Solution(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (dp[n - 1] == -1)
        dp[n - 1] = Solution(n - 1);
    if (n % 3 == 0 && n % 2 == 0)
    {
        if (dp[n / 3] == -1)
            dp[n / 3] = Solution(n / 3);
        if (dp[n / 2] == -1)
            dp[n / 2] = Solution(n / 2);

        std::array<int, 3> arr = { dp[n / 3], dp[n / 2], dp[n - 1] };
        auto it = std::min_element(arr.begin(), arr.end());
        if (*it == dp[n / 3])
            path[n] = n / 3;
        else if (*it == dp[n / 2])
            path[n] = n / 2;
        else
            path[n] = n - 1;
        return *it + 1;
    }
    if (n % 3 == 0)
    {
        if (dp[n / 3] == -1)
            dp[n / 3] = Solution(n / 3);

        std::array<int, 2> arr = { dp[n / 3], dp[n - 1] };
        auto it = std::min_element(arr.begin(), arr.end());
        if (*it == dp[n / 3])
            path[n] = n / 3;
        else
            path[n] = n - 1;
        return *it + 1;
    }
    if (n % 2 == 0)
    {
        if (dp[n / 2] == -1)
            dp[n / 2] = Solution(n / 2);

        std::array<int, 2> arr = { dp[n / 2], dp[n - 1] };
        auto it = std::min_element(arr.begin(), arr.end());
        if (*it == dp[n / 2])
            path[n] = n / 2;
        else
            path[n] = n - 1;
        return *it + 1;
    }
    path[n] = n - 1;
    return dp[n - 1] + 1;
}

int main()
{
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    std::cin >> n;
    dp.resize(n + 1, -1);
    path.resize(n + 1, 0);
    path[2] = 1;

    std::cout << Solution(n) << '\n';

    std::cout << n << '\n';
    int p = path[n];
    while (p != 0)
    {
        std::cout << p << '\n';
        p = path[p];
    }
}