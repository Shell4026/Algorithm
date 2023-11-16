#include <iostream>
#include <vector>


template<typename T>
void Merge(std::vector<T>& v, std::vector<T>& tmp, int& count, const int k, int begin, int middle, int end)
{
	int i = begin;
	int j = middle + 1;
	int t = 0;
	while (i <= middle && j <= end)
	{
		if (v[i] <= v[j])
			tmp[t++] = v[i++];
		else
			tmp[t++] = v[j++];
	}
	while (i <= middle)
		tmp[t++] = v[i++];
	while (j <= end)
		tmp[t++] = v[j++];

	i = begin;
	t = 0;
	while (i <= end)
	{
		++count;
		if (count == k)
			std::cout << tmp[t];
		v[i++] = tmp[t++];
	}
}

template<typename T>
void MergeSort(std::vector<T>& v, std::vector<T>& tmp, int& count, const int k, int begin, int end)
{
	if (begin < end)
	{
		int m = (begin + end) / 2;
		MergeSort(v, tmp, count, k, begin, m);
		MergeSort(v, tmp, count, k, m + 1, end);
		Merge(v, tmp, count, k, begin, m, end);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;

	std::vector<int> arr(n, 0);
	std::vector<int> tmp(n, 0);
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		arr[i] = num;
	}
	int count = 0;
	MergeSort(arr, tmp, count, k, 0, arr.size() - 1);
	if (count < k)
		std::cout << -1;
	return 0;
}
