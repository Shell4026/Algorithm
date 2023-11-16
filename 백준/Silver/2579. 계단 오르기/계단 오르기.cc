#include <iostream>
#include <array>
#include <vector>

int solve(std::vector<int> &score, std::vector<std::vector<int>>& mem, int n, bool one = false)
{
	if (n == 1)
		return score[0];
	
	if (mem[one][n - 1] > 0)
		return mem[one][n - 1];

	if (one)
	{
		if (n == 2)
			return score[1];

		mem[one][n - 1] = solve(score, mem, n - 2) + score[n - 1];
		return mem[one][n - 1];
	}
	else
	{
		if (n == 2)
			return score[0] + score[1];

		mem[one][n - 1] = std::max(solve(score, mem, n - 1, true), solve(score, mem, n - 2)) + score[n - 1];
		return mem[one][n - 1];
	}
}

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> scores(n, 0);
	std::vector<std::vector<int>> mem(2, std::vector<int>(n, 0));

	for (auto&i : scores)
	{
		int score;
		std::cin >> score;
		i = score;
	}
	std::cout << solve(scores, mem, n);
	return 0;
}
