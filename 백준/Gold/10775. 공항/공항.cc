#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
int g, p;

int ans = 0;

int parent[MAX];

int flight[MAX];

int Find(int v)
{
    if(v == parent[v]) return parent[v];
    else return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> g >> p;

    for(int i = 1; i <= g; i++)
    {
        parent[i] = i;
    }

    for(int i = 1; i <= p; i++)
    {
        cin >> flight[i];
    }

    for(int i = 1; i <= p; i++)
    {
        int idx = Find(flight[i]);

        // cout << "idx: " << idx << "\n";
        if(idx == 0) break;
        
        Union(Find(idx), Find(idx-1));
        ans++;

    }

    cout << ans << "\n";

    return 0;
}