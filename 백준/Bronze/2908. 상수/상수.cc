#include <iostream>
#include <string>
#include <algorithm>

int main() 
{
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::reverse(str1.begin(), str1.end());
    std::reverse(str2.begin(), str2.end());

    int n1, n2;
    n1 = std::stoi(str1);
    n2 = std::stoi(str2);
    if (n1 > n2)
        std::cout << n1 << '\n';
    else
        std::cout << n2 << '\n';


    return 0;
}
