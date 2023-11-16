#include <iostream>
#include <vector>

int solution(const std::vector<std::vector<int>>& triangle) {
    std::vector<std::vector<int>> dp;
    int lv = triangle.size();
    for(int i = 0; i < lv; ++i)
    {
        if(triangle[i].size() == 1)
        {
            std::vector<int> v = {triangle[i]};
            dp.push_back(std::move(v));
            continue;
        }
        std::vector<int> v;
        for(int j = 0; j < triangle[i].size(); ++j)
        {
            int val = triangle[i][j];
            int max = val;
            if(j < triangle[i-1].size())
            {
                int parent = dp[i-1][j];
                if(val + parent > max)
                    max = val + parent;
            }
            if(j - 1 >= 0)
            {
                int parent = dp[i-1][j-1];
                if(val + parent > max)
                    max = val + parent;
            }
            v.push_back(max);
        }
        dp.push_back(std::move(v));
    }
    int max = dp[lv-1][0];
    for(int i = 1; i < dp[lv-1].size(); ++i)
    {
        if(dp[lv-1][i] > max)
            max = dp[lv-1][i];
    }
    return max;
}

int main()
{
	std::cout.tie(0)->sync_with_stdio(false);
	std::cin.tie(0);

	int n = 0;
	std::cin >> n;
    
    std::vector<std::vector<int>> input;
    
    for(int i = 0; i < n; ++i)
    {
        std::vector<int> v;
        for(int j = 0; j <= i; ++j)
        {
            int n;
            std::cin >> n;
            v.push_back(n);
        }
        input.push_back(std::move(v));
    }

	
	std::cout << solution(input);
	return 0;
}
