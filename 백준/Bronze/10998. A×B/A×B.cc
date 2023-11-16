#include <iostream>

int main()
{
    int a = 0;
    int b = 0;

    std::cin >> a;
    if (a <= 0)
        return 0;
    std::cin >> b;
    if (b >= 10)
        return 0;

    std::cout << a * b;

    return 0;
}