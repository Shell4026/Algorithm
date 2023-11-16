#include <iostream>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::stack<int> st;
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		if(num != 0)
			st.push(num);
		else
			st.pop();
	}
	int sum = 0;
	while(!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	std::cout << sum;
}
