#include <iostream>
#include <string>
int main()
{
    std::cout.tie(0)->sync_with_stdio(false);
    std::cin.tie(0);

    std::string str;
    std::cin >> str;

    std::cout << str.length();
    return 0;
}
