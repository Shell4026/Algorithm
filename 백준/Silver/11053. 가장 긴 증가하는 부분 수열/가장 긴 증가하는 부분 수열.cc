#include <iostream>
#include <vector>
#include <algorithm>

int solve(std::vector<int>& mem, const std::vector<int>& nums, int n = 0)
{
    if (n == 0)
    {
        if (mem[n] == 0)
            mem[n] = 1;
        return mem[n];
    }

    if (mem[n] == 0)
    {
        int max = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mem[i] == 0)
                mem[i] = solve(mem, nums, i);

            if (nums[n] > nums[i])
            {
                if (mem[i] > max)
                    max = mem[i];
            }
        }
        mem[n] = max + 1;
    }
    return mem[n];
}

int main()
{
    std::cout.tie(0)->sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> numbers(n, 0);
    std::vector<int> mem(n, 0);
    for (int i = 0; i < n; ++i)
        std::cin >> numbers[i];

    solve(mem, numbers, n - 1);

    std::cout << *std::max_element(mem.begin(), mem.end());
    return 0;
}
