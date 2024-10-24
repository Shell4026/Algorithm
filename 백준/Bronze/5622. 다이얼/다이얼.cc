#include <iostream>
#include <string>
#include <algorithm>
#include <array>

int main() 
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::string input;
    std::cin >> input;
    std::array<int, 26> nums{ 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

    int sum = 0;
    for (auto c : input)
    {
        sum += nums[c - 'A'];
    }
    std::cout << sum;
    return 0;
}
