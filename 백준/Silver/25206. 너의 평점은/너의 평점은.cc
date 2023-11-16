#include <iostream>
#include <string>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int credit_sum = 0;
	float sum = 0;
	for (int i = 0; i < 20; ++i)
		{
		std::string name;
		float c;
		std::string score;
		std::cin >> name >> c >> score;

		float score_float = 0.0f;
		if (score == "P")
			continue;
		else if (score == "A+")
			score_float = 4.5;
		else if(score == "A0")
			score_float = 4.0;
		else if (score == "B+")
			score_float = 3.5;
		else if (score == "B0")
			score_float = 3.0;
		else if (score == "C+")
			score_float = 2.5;
		else if (score == "C0")
			score_float = 2.0;
		else if (score == "D+")
			score_float = 1.5;
		else if (score == "D0")
			score_float = 1.0;
		else
			score_float = 0.0;

		credit_sum += c;
		sum += c * score_float;
	}
	std::cout << sum / credit_sum;
	return 0;
}
