#include <bits/stdc++.h>

using namespace std;

int n;

int order[401];
set<int> friends[401];

int board[401][401];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0,- 1, 1};

void GetAns()
{
    for(int k = 1; k <= n*n; k++)
    {
        int cur = order[k];

        int like = -1; // 인접한 칸 중 좋아하는 학생 수
        int empty = -1; // 빈 칸 수
        int x = 0, y = 0; // 해당 행, 열 번호

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // 빈 칸이 아니면 검사 대상 제외
                if(board[i][j] != 0) continue;

                int tmpLike = 0;
                int tmpEmpty = 0;

                for(int dir = 0; dir < 4; dir++)
                {
                    int nX = i + dx[dir];
                    int nY = j + dy[dir];

                    if(nX < 1 || nX > n || nY < 1 || nY > n) continue;

                    // 인접한 칸 중 좋아하는 학생 수 구하기
                    if(friends[cur].count(board[nX][nY]) > 0) tmpLike++;

                    // 빈 칸 수 구하기
                    if(board[nX][nY] == 0) tmpEmpty++;

                }

                // 1) 좋아하는 학생 우선
                if(like < tmpLike)
                {
                    like = tmpLike;
                    empty = tmpEmpty;
                    x = i;
                    y = j;
                }

                // 2) 빈 칸 우선
                else if(like == tmpLike && empty < tmpEmpty)
                {
                    like = tmpLike;
                    empty = tmpEmpty;
                    x = i;
                    y = j;
                }

                // 3) 행 번호 우선
                else if(like == tmpLike && empty == tmpEmpty && x > i)
                {
                    like = tmpLike;
                    empty = tmpEmpty;
                    x = i;
                    y = j;
                }

                // 열 번호 우선
                else if(like == tmpLike && empty == tmpEmpty && x == i && y > j)
                {
                    like = tmpLike;
                    empty = tmpEmpty;
                    x = i;
                    y = j;
                }
            }
        }

        board[x][y] = cur;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n*n; i++)
    {
        int a;
        cin >> a;

        order[i] = a;

        for(int j = 0; j < 4; j++)
        {
            int b;
            cin >> b;

            friends[a].insert(b);
        }
    }

    GetAns();

    int ans = 0;

    // 만족도 구하기
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int cnt = 0;
            int cur = board[i][j];
            for(int dir = 0; dir < 4; dir++)
            {
                int nX = i + dx[dir];
                int nY = j + dy[dir];

                if(nX < 1 || nX > n || nY < 1 || nY > n) continue;

                if(friends[cur].count(board[nX][nY]) > 0) cnt++;
            }

            if(cnt == 0) continue;
            ans += pow(10, cnt - 1);
        }
    }

    cout << ans << "\n";

    return 0;
}