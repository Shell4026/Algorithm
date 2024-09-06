#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

auto SetArr(std::vector<std::vector<int>> &dp, int w, int h, int addNum) -> int
{
    int up = 0, left = 0, upLeft = 0;
    if (w - 1 >= 0 && h - 1 >= 0)
        upLeft = dp[h - 1][w - 1];
    if (w - 1 >= 0)
        left = dp[h][w - 1];
    if (h - 1 >= 0)
        up = dp[h - 1][w];

    dp[w][h] = std::max({up, left, upLeft}) + addNum;
    return dp[w][h];
}

int main()
{
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input1{};
    std::string input2{};

    std::cin >> input1 >> input2;

    std::vector<std::vector<int>> dp(input2.size(), std::vector<int>(input1.size(), 0));
    int max = 0;

    for (int h = 0; h < input2.size(); ++h)
    {
        for (int w = 0; w < input1.size(); ++w)
        {
            if (input1[w] == input2[h])
            {
                if (w - 1 >= 0 && h - 1 >= 0)
                    dp[h][w] = dp[h - 1][w - 1] + 1;
                else
                    dp[h][w] = 1;

                if (dp[h][w] > max)
                    max = dp[h][w];
            }
            else
            {
                int left = 0, up = 0;
                if (w - 1 >= 0)
                    left = dp[h][w - 1];
                if (h - 1 >= 0)
                    up = dp[h - 1][w];
                dp[h][w] = std::max(left, up);
                if (dp[h][w] > max)
                    max = dp[h][w];
            }
        }
    }

    std::cout << max;

    return 0;
}