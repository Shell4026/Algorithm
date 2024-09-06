#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using Pair = std::pair<int, int>;
std::vector<Pair> input{};
std::vector<int> dp{};

int main()
{
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    input.resize(n, Pair{0, 0});

    for (int i = 0; i < n; ++i)
    {
        Pair tmp;
        std::cin >> tmp.first >> tmp.second;
        input[i] = tmp;
    }
    std::sort(input.begin(), input.end(), [&](const Pair& left, const Pair& right)
        {
            return left.first < right.first;
        }
    );

    dp.push_back(input[0].second);
    for (int i = 1; i < n; ++i)
    {
        if (dp.back() < input[i].second)
        {
            dp.push_back(input[i].second);
        }
        else
        {
            auto it = std::lower_bound(dp.begin(), dp.end(), input[i].second);
            *it = input[i].second;
        }
    }

    std::cout << n - dp.size();
    return 0;
}