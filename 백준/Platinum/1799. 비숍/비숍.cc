#include <bits/stdc++.h>

using namespace std;

int n;

// 0 : 놓을 수 없음
// 1 : 놓을 수 있음
int board[11][11];

int l[21]; // 좌측 대각선
int r[21]; // 우측 대각선

// ans[0] : 흰색 칸에만 놨을 때 설치 가능한 최대 비숍 수
// ans[1] : 검정색 칸에만 놨을 때 설치 간으한 최대 비숍 수
int ans[2];

// <좌대각선 번호, 현재 비숍 수>
void func(int x, int y, int cnt, int color)
{
    if(y >= n)
    {
        x++;

        // 이전 행의 시작이 0이었다면 이번엔 1부터 시작
        if(y % 2 == 0) y = 1;

        // 이전 행의 시작이 1이었다면 이번엔 0부터 시작
        else y = 0;
    }   
    
    // 마지막 행까지 오면 정답 저장 후 리턴
    if(x >= n)
    {
        ans[color] = max(ans[color], cnt);
        return;
    }

    // 현재 자리에 놓을 수 있다면 놓기
    if(board[x][y] == 1 && l[(n - 1) - (y - x)] == 0 && r[x + y] == 0)
    {
        l[(n - 1) - (y - x)] = 1;
        r[x + y] = 1;

        // 지금 자리에 놓고 다음 같은 색깔 칸으로 이동
        func(x, y + 2, cnt + 1, color);

        l[(n - 1) - (y - x)] = 0;
        r[x + y] = 0;
    }

    // 다음 같은 색깔 칸으로 이동
    func(x, y + 2, cnt, color);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    // 흰색 칸에만 놓기
    func(0, 0, 0, 0);

    // 검정색 칸에만 놓기
    func(0, 1, 0, 1);

    // 흰색 칸에만 비숍 놓는 경우 + 검은색 칸에만 비숍 놓는 경우가 정답
    cout << ans[0] + ans[1] << "\n";

    return 0;
}