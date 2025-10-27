#include <bits/stdc++.h>

using namespace std;

#define MAX 10001
int tc;
int n, d, c; // 컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터 번호

vector<pair<int, int>> adj[MAX]; // <감염 시간, 컴퓨터 번호>
int dist[MAX];

void Dijkstra(int x)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[x] = 0;
    pq.push({dist[x], x});

    while(!pq.empty())
    {
        auto [curT, cur] = pq.top();
        pq.pop();

        for(auto [nT, nxt] : adj[cur])
        {
            if(dist[nxt] > curT + nT)
            {
                dist[nxt] = curT + nT;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;

    while(tc--)
    {
        cin >> n >> d >> c;

        for(int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }

        for(int i = 0; i < d; i++)
        {
            int a, b, s;
            cin >> a >> b >> s;

            adj[b].push_back({s, a});
        }

        for(int i = 1; i <= n; i++) dist[i] = INT_MAX;

        Dijkstra(c);

        int cnt = 0;
        int idx = c;
        
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] != INT_MAX)
            {
                cnt++;
                if(dist[idx] < dist[i]) idx = i;
            }
        }

        cout << cnt << " " << dist[idx] << "\n";
        
    }

    

    return 0;
}