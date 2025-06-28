#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
int t, n;

int board[MAX];
bool vis[MAX];
bool isFinished[MAX]; // 탐색 마친 노드

int cnt = 0;

void DFS(int cur)
{
    vis[cur] = true;
    int nxt = board[cur];

    if(!vis[nxt]) DFS(nxt);

    else if(!isFinished[nxt])
    {
        for(int i = nxt; i != cur; i = board[i])
        {
            cnt--;
        }
        cnt--;
    }

    isFinished[cur] = true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        cnt = n;

        for(int i = 1; i <= n; i++)
        {
            cin >> board[i];

            vis[i] = isFinished[i] = false;
        }

        for(int i = 1; i <= n; i++)
        {   
            if(!vis[i])
            {
                DFS(i);
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}