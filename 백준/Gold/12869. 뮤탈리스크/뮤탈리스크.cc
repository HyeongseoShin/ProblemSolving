#include <bits/stdc++.h>

using namespace std;

int n;

int scv[3];

// 한 번에 공격에서 scv에 가할 수 있는 대미지
int atk[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 3, 9}, {1, 9, 3}};

int ans = INT_MAX;

int dist[61][61][61];

void bfs()
{
    memset(dist, -1, sizeof(dist));
    dist[scv[0]][scv[1]][scv[2]] = 0;

    queue<tuple<int, int, int>> q;
    q.push({scv[0], scv[1], scv[2]});

    while(!q.empty())
    {
        auto [a, b, c] = q.front();
        q.pop();

        if(a == 0 && b == 0 && c == 0)
        {
            ans = dist[a][b][c];
            return;
        }

        for(int i = 0; i < 6; i++)
        {
            int nA = max(0, a - atk[i][0]);
            int nB = max(0, b - atk[i][1]);
            int nC = max(0, c - atk[i][2]);

            if(dist[nA][nB][nC] > -1) continue;

            dist[nA][nB][nC] = dist[a][b][c] + 1;

            q.push({nA, nB, nC});
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> scv[i];

    bfs();

    cout << ans << "\n";;

    return 0;
}