#include <iostream>

int main()
{
    std::cout.precision(12);
    int a = 0;
    int b = 0;
    double result = 0.f;

    std::cin >> a;
    if (a <= 0)
        return 0;
    std::cin >> b;
    if (b >= 10 && b == 0)
        return 0;

    result = static_cast<double>(a) / static_cast<double>(b);
    std::cout << result;
    return 0;
}