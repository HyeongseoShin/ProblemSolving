// MST - 크루스칼 알고리즘
#include <bits/stdc++.h>

using namespace std;

int parent[101];

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

int solution(int n, vector<vector<int>> costs) {
    int ans = 0;
    int m = (int)costs.size();
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    for(int i = 0; i < m; i++)
    {
        int from = costs[i][0];
        int to = costs[i][1];
        int cost = costs[i][2];
        
        pq.push({cost, from, to});
    }
    
    int cnt = 0;
    while(cnt < n - 1)
    {
        auto [cost, from, to] = pq.top();
        pq.pop();
                
        if(Find(from) != Find(to))
        {
            Union(from, to);
            ans += cost;
            cnt++;
        }
    }
    
    return ans;
}