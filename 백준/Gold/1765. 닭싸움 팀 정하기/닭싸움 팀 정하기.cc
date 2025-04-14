#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> parent;

// F만 저장
vector<int> adj[1005];

vector<int> enemy[1005];

bool vis[1005];

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

    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

void EnemyDFS(int st, int v, int depth)
{
    if(depth == 2)
    {
        if(Find(parent[st]) != Find(parent[v]))
        {
            adj[st].push_back(v);
            adj[v].push_back(st);
            Union(st, v);
        }

        return;
    }

    vis[v] = true;
    for(int nxt : enemy[v])
    {
        if(vis[nxt]) continue;
        EnemyDFS(st, nxt, depth + 1);
    }
}

void FriendDFS(int st, int v)
{
    if(Find(parent[st]) != Find(parent[v]))
    {
        Union(st, v);
    }

    vis[v] = true;
    for(int nxt : adj[v])
    {
        if(vis[nxt]) continue;
        FriendDFS(st, nxt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    parent.resize(n+1);

    while(m--)
    {
        char type;
        int p, q;

        cin >> type >> p >> q;

        if(type == 'F')
        {
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
        else
        {
            enemy[p].push_back(q);
            enemy[q].push_back(p);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    // 원수 DFS를 통해 새로운 친구 에지 추가
    for(int i = 1; i <= n; i++)
    {
        fill(vis, vis + 1005, false);
        EnemyDFS(i, i, 0);
    }

    for(int i = 1; i <= n; i++)
    {
        fill(vis, vis + 1005, false);
        FriendDFS(i, i);
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     cout << parent[i] << " ";
    // }
    // cout << "\n";

    sort(parent.begin(), parent.end());
    parent.erase(unique(parent.begin(), parent.end()), parent.end());

    cout << parent.size() - 1 << "\n";




    return 0;
}