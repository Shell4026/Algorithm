#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	bool students[30] = { 0, };
	for (int i = 0; i < 28; ++i)
	{
		int a;
		std::cin >> a;
		students[a - 1] = true;
	}
	int num = 0;
	for (int i = 0; i < 30; ++i)
	{
		if (num == 2)
			break;
		if (students[i] == false)
		{
			std::cout << i + 1 << '\n';
			++num;
		}
	}
	return 0;
}
