#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int n, k;
int dist[MAX];

int bfs()
{
    fill(dist, dist + MAX, INT_MAX);
    dist[n] = 0;

    queue<int> q;
    q.push(n);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(cur == k) break;

        int nxt = cur - 1;
        if(nxt >= 0 && dist[nxt] > dist[cur] + 1)
        {
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }

        nxt = cur + 1;
        if(nxt < MAX && dist[nxt] > dist[cur] + 1)
        {
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }

        nxt = cur * 2;
        if(nxt >= 0 && nxt < MAX && dist[nxt] > dist[cur])
        {
            dist[nxt] = dist[cur];
            q.push(nxt);
        }
    }

    return dist[k];
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int ans = bfs();

    cout << ans << "\n";

    return 0;
}