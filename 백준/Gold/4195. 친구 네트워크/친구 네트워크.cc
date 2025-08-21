#include <bits/stdc++.h>

using namespace std;

int t, f;

int idx = 0;
map<string, int> idxMap;
int parent[200001];
int sz[200001];

int Find(int v)
{
    if(parent[v] == v) return parent[v];
    else return parent[v] = Find(parent[v]);
}
int Union(int from, int to)
{
    from = Find(from);
    to = Find(to);

    if(from != to)
    {
        if(sz[from] < sz[to]) swap(from, to);
        parent[to] = from;
        sz[from] += sz[to];
    }

    return sz[from];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> f;

        for(int i = 0; i < 200001; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }

        idx = 0;
        idxMap.clear();

        while(f--)
        {
            string from, to;

            cin >> from >> to;

            // 둘다 parent 없으면 일단 추가
            if(idxMap.find(from) == idxMap.end()) idxMap[from] = idx++;
            if(idxMap.find(to) == idxMap.end()) idxMap[to] = idx++;

            int idxFrom, idxTo;

            idxFrom = idxMap[from];
            idxTo = idxMap[to];
            
            cout << Union(idxFrom, idxTo) << "\n";
        }
    }

    return 0;
}