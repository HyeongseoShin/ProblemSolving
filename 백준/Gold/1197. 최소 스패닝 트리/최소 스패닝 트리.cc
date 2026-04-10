#include <bits/stdc++.h>

using namespace std;

int v, e;

int parent[10001];

int Find(int v)
{
    if(parent[v] == v) return parent[v];
    return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> edges;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    
    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push({c, a, b});
    }

    for(int i = 1; i <= v; i++) parent[i] = i;

    int ans = 0;
    int cnt = 0;
    while(cnt < v - 1)
    {
        auto [w, from, to] = edges.top();
        edges.pop();

        if(Find(from) != Find(to))
        {
            Union(from, to);
            cnt++;
            ans += w;
        }
    }

    cout << ans << "\n";

    return 0;
}