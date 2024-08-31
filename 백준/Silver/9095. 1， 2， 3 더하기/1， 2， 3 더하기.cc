#include <iostream>
#include <vector>
#include <deque>
#include <array>

std::array<int, 10> dp{ 1, 2, 4 };

int Solution(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;

    if (dp[n - 1] == 0)
    {
        for (int i = 1; i <= 3; ++i)
        {
            dp[n - 1] += Solution(n - i);
        }
    }
    return dp[n - 1];
}


int main()
{
    int cnt = 0;
    std::cin >> cnt;
    for (int i = 0; i < cnt; ++i)
    {
        int n = 0;
        std::cin >> n;
        std::cout << Solution(n) << '\n';
    }
}