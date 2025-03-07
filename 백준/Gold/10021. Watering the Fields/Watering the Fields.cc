#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 3000001

int n, c;

// (x, y)
vector<pair<int, int>> farm;

// 거리 오름차순 정렬
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int parent[2005];


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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        farm.push_back({x, y});

        parent[i] = i;
    }

    for(int i = 0; i < farm.size(); i++)
    {   
        for(int j = i+1; j < farm.size(); j++)
        {
            int dist = (farm[i].first - farm[j].first) * (farm[i].first - farm[j].first)
            + (farm[i].second - farm[j].second) * (farm[i].second - farm[j].second);

            if(dist < c) continue;
            pq.push({dist, i, j});
        }
    }

    int cnt = 0;
    int ans = 0;
    // MST의 크기가 n-1이 될때까지 진행
    while(!pq.empty() && cnt < n - 1)
    {
        auto [curEdge, curU, curV] = pq.top();
        pq.pop();

        if(Find(curU) != Find(curV))
        {
            Union(curU, curV);
            cnt++;
            ans += curEdge;
        }
    }

    if(cnt < n - 1)
    {
        cout << "-1\n";
    }
    else cout << ans << "\n";
    
    return 0;
}