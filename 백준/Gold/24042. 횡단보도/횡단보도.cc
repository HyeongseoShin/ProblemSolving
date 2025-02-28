#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll n, m;

// (도착지점, 신호등 바뀌는 시간)
vector<pair<ll, ll>> adj[100005];

vector<ll> dst;

void Dijkstra()
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    
    dst[1] = 0;
    pq.push({dst[1], 1});

    while(!pq.empty())
    {
        auto [curTime, curPos] = pq.top();
        pq.pop();

        ll cycle = curTime / m; // 현재까지 주기
        ll t = curTime % m; // 한 주기 내에서의 시간

        for(auto [nTime, nPos]: adj[curPos])
        {
            // 현재 사이클에서 도달 가능
            if(t + 1 <= nTime)
            {
                if(dst[nPos] > cycle * m + nTime)
                {
                    dst[nPos] = cycle * m + nTime;
                    pq.push({dst[nPos], nPos});
                }
            }

            // 현재 사이클에서 도달 불가능
            else
            {
                if(dst[nPos] > (cycle + 1) * m + nTime)
                {
                    dst[nPos] = (cycle + 1) * m + nTime;
                    pq.push({dst[nPos], nPos});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    dst.resize(n+1, LLONG_MAX);

    for(ll i = 1; i <= m; i++)
    {
        ll a, b;
        cin >> a >> b;

        adj[a].push_back({i, b});
        adj[b].push_back({i, a});
    }

    Dijkstra();

    cout << dst[n] << "\n";

    return 0;
}