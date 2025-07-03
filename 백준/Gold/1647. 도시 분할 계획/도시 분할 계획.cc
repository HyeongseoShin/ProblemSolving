#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int n, m;

int parent[MAX];

int Find(int v)
{
    if(v == parent[v]) return parent[v];
    return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        pq.push({c, a, b});
    }

    int cnt = 0;
    int longest = 0;
    int weights = 0;

    while(cnt < n - 1)
    {
        auto [w, u, v] = pq.top();
        pq.pop();

        if(Find(u) != Find(v))
        {
            Union(u, v);
            cnt++;

            longest = max(longest, w);
            weights += w;
            
        }
    }

    
    int ans = weights - longest;
    cout << ans << "\n";
    
    return 0;
}