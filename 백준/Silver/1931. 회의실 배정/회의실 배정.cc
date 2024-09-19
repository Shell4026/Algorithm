#include <iostream>
#include <vector>
#include <algorithm>

struct Meeting
{
	uint32_t start;
	uint32_t end;

	bool operator<(const Meeting& other) const
	{
		if (end == other.end)
			return start < other.start;
		return end < other.end;
	}
};

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<Meeting> meetingsSorted(n);

	for (int i = 0; i < n; ++i)
		std::cin >> meetingsSorted[i].start >> meetingsSorted[i].end;

	std::sort(meetingsSorted.begin(), meetingsSorted.end());
	
	int cnt = 1;
	uint32_t end = meetingsSorted[0].end;

	for (int i = 1; i < n; ++i)
	{
		if (meetingsSorted[i].start < end)
			continue;
		end = meetingsSorted[i].end;

		++cnt;
	}
	std::cout << cnt;
	return 0;
}