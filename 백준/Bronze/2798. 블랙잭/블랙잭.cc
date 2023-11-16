#include <iostream>
#include <vector>

int solution(int n, int m, std::vector<int>& card_arr)
{
    int max = 0;
    for (int i = 0; i < card_arr.size() - 2; ++i)
    {
        if (card_arr[i] > m)
            continue;
        for (int j = i + 1; j < card_arr.size() - 1; ++j)
        {
            if (card_arr[i] + card_arr[j] > m)
                continue;
            for (int k = j + 1; k < card_arr.size(); ++k)
            {
                int sum = card_arr[i] + card_arr[j] + card_arr[k];
                if (sum > m)
                    continue;
                if (sum > max)
                    max = sum;
            }
        }
    }
    return max;
}

int main()
{
	std::cout.tie(0)->sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	int m = 0;
	std::cin >> n >> m;

    std::vector<int> card_arr;
    for (int i = 0; i < n; ++i)
    {
        int num;
        std::cin >> num;
        card_arr.push_back(num);
    }

	std::cout << solution(n, m, card_arr);
	return 0;
}
