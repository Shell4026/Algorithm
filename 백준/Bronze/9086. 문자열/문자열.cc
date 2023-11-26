#include <iostream>
#include <string>
int main()
{
    std::cout.tie(0)->sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string str;
        std::cin >> str;
        std::cout << str[0] << str[str.size() - 1] << '\n';
    }
    return 0;
}
