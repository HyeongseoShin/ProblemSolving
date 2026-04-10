#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

vector<tuple<ll, ll, ll>> edges;

ll dist[501];
bool isCycle = false;

void getAns()
{
    // 그래프 연결
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            auto [w, s, e] = edges[j];
            
            if(dist[s] != LLONG_MAX && dist[e] > dist[s] + w)
            {
                dist[e] = dist[s] + w;
            }
            
        }
    }

    // 음수 사이클 확인
    // 모든 edges 순회하며 업데이트 발생 -> 사이클
    for(int i = 0; i < m; i++)
    {
        auto [w, s, e] = edges[i];
        if(dist[s] != LLONG_MAX && dist[e] > dist[s] + w)
        {
            isCycle = true;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }

    fill(dist, dist + n + 1, LLONG_MAX);
    dist[1] = 0;
    getAns();

    if(isCycle)
    {
        cout << "-1\n";
        return 0;
    }

    for(int i = 2; i <= n; i++)
    {
        if(dist[i] == LLONG_MAX) dist[i] = -1;
        cout << dist[i] << "\n";
    }

    return 0;
}