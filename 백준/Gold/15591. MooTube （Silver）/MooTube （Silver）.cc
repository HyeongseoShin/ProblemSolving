#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, q;

ll dst[5003][5003];
ll usado[5003][5003];

// (목적지, 유사도)
vector<pair<ll, ll>> adj[5003];

bool vis[5003];

int BFS(ll x, ll k)
{
    fill(vis, vis + 5003, false);
    ll ret = 0;

    vis[x] = true;
    queue<ll> q;
    q.push(x);

    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();

        for(auto [nxt, usado] : adj[cur])
        {
            if(vis[nxt]) continue;
            if(usado >= k)
            {
                vis[nxt] = true;
                ret++;
                q.push(nxt);
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for(int i = 0; i < n-1; i++)
    {
        ll p, q, r;
        cin >> p >> q >> r;

        adj[p].push_back({q, r});
        adj[q].push_back({p, r});
    }

    while(q--)
    {
        ll k, v;

        cin >> k >> v;

        ll result = BFS(v, k);

        cout << result << "\n";
    }

    return 0;
}