#include <bits/stdc++.h>

using namespace std;

int v, e;

tuple<int, int, int> edges[100005]; // (w, u, v)
int parent[10005]; // 각 정점의 Parent 저장 (Union & Find 위함)

int Find(int v)
{
    if(parent[v] == v)
    {
        return parent[v];
    }
    
    return parent[v] = Find(parent[v]);
}


void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v1 < v2)
    {
        parent[v2] = v1;
    }

    else if(v1 > v2)
    {
        parent[v1] = v2;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;

    
    for(int i = 1; i <= v; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < e; i++)
    {
        cin >> get<1>(edges[i]) >> get<2>(edges[i]) >> get<0>(edges[i]);
        
    }

    sort(edges, edges + e);

    int cnt = 0;
    int ans = 0;

    for(int i = 0; i < e; i++)
    {
        int u1, v1, w1;
        tie(w1, u1, v1) = edges[i];

        if(Find(u1) != Find(v1))
        {
            Union(u1, v1);
            ans += w1;
            cnt++;
        }

        if(cnt == v - 1)
        {
            break;
        }
        
    }

    cout << ans << "\n";

    return 0;
}