#include <bits/stdc++.h>

using namespace std;

// 동 서 남 북
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n;

// 동 서 남 북 확률 저장
double prob[4];

// 단순한 경우의 수
double cnt = 0;

// x : -14 ~ 14
// y : -14 ~ 14
bool vis[51][51]; // 방문 확인 배열

void DFS(int x, int y, int cur, double val)
{
    // 끝까지 도달함 => 단순한 경로 => 횟수 저장
    if(cur == n)
    {
        cnt += val;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        // 이미 방문했다면 패스
        if(vis[nX][nY]) continue;

        vis[nX][nY] = true;
        DFS(nX, nY, cur + 1, val * prob[i]);
        vis[nX][nY] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < 4; i++)
    {
        cin >> prob[i];

        prob[i] /= 100.0;
    }
    cout << "\n";

    vis[25][25] = true;
    DFS(25, 25, 0, 1);

    cout << fixed;
    cout.precision(9);
    
    cout << cnt << "\n";
    
    return 0;
}