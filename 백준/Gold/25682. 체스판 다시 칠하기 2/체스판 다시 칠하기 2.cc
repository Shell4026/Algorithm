#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<int>> sumBlack(N + 1, std::vector<int>(M + 1, 0));
    std::vector<std::vector<int>> sumWhite(N + 1, std::vector<int>(M + 1, 0));

    // 보드 입력
    std::vector<std::string> board(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> board[i];
    }

    // 누적 합 계산
    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= M; ++x)
        {
            char color = board[y - 1][x - 1];
            int addBlack = 0;
            int addWhite = 0;

            if ((x + y) % 2 == 0)
            {
                // 시작 색상이 'B'인 경우
                if (color != 'B') addBlack = 1;
                // 시작 색상이 'W'인 경우
                if (color != 'W') addWhite = 1;
            }
            else
            {
                if (color != 'W') addBlack = 1;
                if (color != 'B') addWhite = 1;
            }

            sumBlack[y][x] = sumBlack[y - 1][x] + sumBlack[y][x - 1] - sumBlack[y - 1][x - 1] + addBlack;
            sumWhite[y][x] = sumWhite[y - 1][x] + sumWhite[y][x - 1] - sumWhite[y - 1][x - 1] + addWhite;
        }
    }

    int minRepaint = K * K;
    for (int y = K; y <= N; ++y)
    {
        for (int x = K; x <= M; ++x)
        {
            int totalBlack = sumBlack[y][x] - sumBlack[y - K][x] - sumBlack[y][x - K] + sumBlack[y - K][x - K];
            int totalWhite = sumWhite[y][x] - sumWhite[y - K][x] - sumWhite[y][x - K] + sumWhite[y - K][x - K];

            int currentMin = std::min(totalBlack, totalWhite);
            minRepaint = std::min(minRepaint, currentMin);
        }
    }

    std::cout << minRepaint << "\n";
    return 0;
}
