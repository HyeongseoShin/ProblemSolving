#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
int dist[MAX];
int cnt[MAX];

int n, k;

void BFS(int x)
{
    queue<int> q;
    q.push(x);

    dist[x] = 0;
    cnt[x] = 1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int nxt : {cur+1, cur-1, cur*2})
        {
            if(nxt < 0 || nxt > 100000) continue;

            if(dist[nxt] == -1)
            {
                dist[nxt] = dist[cur] + 1;
                cnt[nxt] += cnt[cur];
                q.push(nxt);
            }

            else if(dist[nxt] == dist[cur] + 1) cnt[nxt] += cnt[cur];
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    fill(dist, dist + MAX, -1);

    BFS(n);

    cout << dist[k] << "\n";
    cout << cnt[k] << "\n";

    return 0;
}