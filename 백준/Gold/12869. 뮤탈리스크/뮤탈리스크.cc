#include <bits/stdc++.h>

using namespace std;

int n;

int scv[3];

// 한 번에 공격에서 scv에 가할 수 있는 대미지
int atk[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 3, 9}, {1, 9, 3}};

int ans = INT_MAX;

int vis[61][61][61];

void bfs()
{
    vis[scv[0]][scv[1]][scv[2]] = true;

    queue<pair<int, vector<int>>> q;
    q.push({0, {scv[0], scv[1], scv[2]}});

    while(!q.empty())
    {
        auto [cnt, curV] = q.front();
        q.pop();

        if(curV[0] == 0 && curV[1] == 0 && curV[2] == 0)
        {
            ans = cnt;
            return;
        }

        for(int i = 0; i < 6; i++)
        {
            vector<int> tmp;
            tmp = curV;
            for(int j = 0; j < 3; j++)
            {
                tmp[j] -= atk[i][j];
                if(tmp[j] < 0) tmp[j] = 0;
            }

            if(vis[tmp[0]][tmp[1]][tmp[2]]) continue;

            vis[tmp[0]][tmp[1]][tmp[2]] = true;

            q.push({cnt+1, tmp});
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