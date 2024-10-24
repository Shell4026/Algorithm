#include <iostream>

#include <array>
#include <vector>
#include <algorithm>
#include <limits>

std::array<int, 500> input;
std::array<std::array<int, 500>, 500> dp;
std::array<int, 500> sum;

void Solve(int start, int end)
{
    if (start == end)
    {
        dp[start][end] = 0;
        return;
    }
    if (end - start == 1)
    {
        dp[start][end] = input[start] + input[end];
        return;
    }

    int min = std::numeric_limits<int>::max();

    for (int pivot = start; pivot < end; ++pivot)
    {
        if (dp[start][pivot] == -1)
            Solve(start, pivot);
        if (dp[pivot + 1][end] == -1)
            Solve(pivot + 1, end);
        int tmp = dp[start][pivot] + dp[pivot + 1][end];

        if (tmp < min)
        {
            min = tmp;
        }
    }

    dp[start][end] = min + sum[end] - (start >= 1 ? sum[start - 1] : 0);
}

int main() 
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        for (auto& arr : dp)
            arr.fill(-1);
        for (auto& s : sum)
            s = 0;

        int n;
        std::cin >> n;
        for (int j = 0; j < n; ++j)
        {
            std::cin >> input[j];
            if (j >= 1)
                sum[j] = sum[j - 1] + input[j];
            else
                sum[0] = input[j];
        }
        Solve(0, n - 1);
        std::cout << dp[0][n - 1] << '\n';
    }
    return 0;
}
