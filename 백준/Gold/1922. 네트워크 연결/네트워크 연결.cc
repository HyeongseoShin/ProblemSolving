#include <bits/stdc++.h>

using namespace std;

int parent[1001];
int n, m;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int Find(int v)
{
    if(v == parent[v]) return parent[v];
    return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v2 > v1) parent[v2] = v1;
    else parent[v1] = v2;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        pq.push({c, a, b});
    }

    for(int i = 1; i <= n; i++) parent[i] = i;

    int cnt = 0;
    int ans = 0;

    while(cnt < n - 1)
    {
        auto [c, a, b] = pq.top();

        if(Find(a) != Find(b))
        {
            Union(a, b);
            cnt++;
            ans += c;
        }

        pq.pop();
    }

    cout << ans << "\n";

    return 0;
}