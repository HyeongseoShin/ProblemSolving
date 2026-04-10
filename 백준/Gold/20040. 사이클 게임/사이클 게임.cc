#include <bits/stdc++.h>

using namespace std;

int n, m;

int parent[500001];

int find(int v)
{
    if(parent[v] == v) return parent[v];
    return parent[v] = find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = find(v1);
    v2 = find(v2);
    
    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) parent[i] = i;

    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        if(find(x) != find(y)) Union(x, y);
        else if(ans == 0) ans = i;
    }

    cout << ans << "\n";
    

    return 0;
}