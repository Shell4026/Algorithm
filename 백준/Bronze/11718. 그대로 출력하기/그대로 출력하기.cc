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
    while (std::getline(std::cin, input))
    {
        std::cout << input << '\n';
    }
    return 0;
}
