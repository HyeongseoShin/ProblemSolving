#include <bits/stdc++.h>

using namespace std;

int n, m, h;

bool board[31][11];

int ans = 4;

// 각 번호마다 제대로 도착하는지 확인
bool Check()
{
    // 도착점 순회
    for(int i = 1; i <= n; i++)
    {
        // 출발점 셋팅
        int pos = i;
        for(int j = 1; j <= h; j++)
        {
            if(board[j][pos]) pos++;
            else if(board[j][pos - 1]) pos--;
        }

        // 도착점 다르면 실패
        if(pos != i) return false;
    }
    
    return true;
}

void DFS(int x, int cnt)
{
    // 설치 개수가 현재 최소보다 크면 리턴
    if(cnt >= ans) return;

    // 모두 끝에 도달하면 정답 업데이트
    if(Check())
    {
        ans = cnt;
    }

    // 아래로 한 칸씩 내려가며 각 출발점마다 다리 설치
    for(int i = x; i <= h; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(board[i][j] || board[i][j+1] || board[i][j-1]) continue;

            board[i][j] = true;
            DFS(i, cnt + 1);
            board[i][j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        board[a][b] = true;
    }

    DFS(1, 0);

    if(ans > 3) ans = -1;

    cout << ans << "\n";

    return 0;
}