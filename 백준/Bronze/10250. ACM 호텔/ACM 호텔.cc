#include <iostream>
#include <string>
int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int w, h, num;
		std::cin >> h >> w >> num;

		int w_count = 0;
		while (w > 0)
		{
			w /= 10;
			++w_count;
		}

		int height = num % h;
		if (height == 0)
			height = h;
		int width = num / h;
		if (num % h == 0)
			width -= 1;
		std::string prefix = std::to_string(height);
		std::string suffix = std::to_string(width + 1);

		if (suffix.length() < 2)
		{
			suffix = '0' + suffix;
		}

		std::cout << prefix << suffix << '\n';
	}
	return 0;
}
