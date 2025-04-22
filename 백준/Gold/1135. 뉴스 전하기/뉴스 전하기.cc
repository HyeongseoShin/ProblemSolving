#include <bits/stdc++.h>

using namespace std;

int n;

int board[51];

vector<int> adj[51];

int DFS(int cur)
{
    // 리프 노드
    if(adj[cur].empty()) return 1;

    vector<int> child; // 현재 노드의 자식 노드들의 방문 총 횟수

    for(auto nxt : adj[cur])
    {
        child.push_back(DFS(nxt) + 1);
    }

    sort(child.begin(), child.end(), greater<>());

    int ret = 0;

    for(int i = 0; i < child.size(); i++)
    {
        ret = max(ret, child[i] + i);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // 각 노드별 자식 추가
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
        
        if(i == 0) continue;

        adj[board[i]].push_back(i);
    }

    int ans = DFS(0);

    cout << ans - 1 << "\n";
    
    return 0;
}