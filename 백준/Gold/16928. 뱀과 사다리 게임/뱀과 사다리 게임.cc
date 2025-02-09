// https://www.acmicpc.net/problem/16928

#include <bits/stdc++.h>

using namespace std;

int n, m; // n: 사다리 수, m: 뱀의 수

int lsInfo[101];
bool vis[101];

int cur = 0;

void BFS(int x, int cnt)
{
    queue<pair<int, int>> q;
    q.push({x, cnt});

    vis[x] = true;

    while(!q.empty())
    {
        auto [curPos, curCnt] = q.front();
        q.pop();

        if(curPos == 100)
        {
            cout << curCnt << "\n";
            break;
        }

        for(int i = 1; i <= 6; i++)
        {
            int nPos = curPos + i;

            if(nPos > 100) continue;

            int newPos = nPos;

            if(lsInfo[nPos] != 0)
            {
                newPos = lsInfo[nPos];
            }

            if(vis[newPos]) continue;

            vis[newPos] = true;

            q.push({newPos, curCnt + 1});
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 사다리 위치 저장
    for(int i = 0; i < n; i++)
    {
        int from, to;
        cin >> from >> to;

        lsInfo[from] = to;
    }

    // 뱀 위치 저장
    for(int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;

        lsInfo[from] = to;
    }

    BFS(1, 0);

    return 0;
}