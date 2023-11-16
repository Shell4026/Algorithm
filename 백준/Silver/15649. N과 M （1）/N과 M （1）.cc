#include <iostream>

int arr[9] = { 0 };
bool visited[9] = { false };

void dfs(int n, int m, int idx = 0)
{
    if (idx == m)
    {
        for (int i = 0; i < m; ++i)
            std::cout << arr[i] << ' ';
        std::cout << '\n';
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == false)
            arr[idx] = i + 1;
        else
            continue;
        visited[i] = true;
        dfs(n, m, idx + 1);
        visited[i] = false;
    }
}

int main()
{
    std::cout.tie(0)->sync_with_stdio(false);
    std::cin.tie(0);
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    dfs(n, m);

    return 0;
}
