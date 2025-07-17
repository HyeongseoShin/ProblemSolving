#include <bits/stdc++.h>

using namespace std;

int n;

// 행성 (비용, 출발, 도착)
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

// 행성(x, y, z)
vector<tuple<int, int, int>> v;

int parent[100001];

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

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x, y, z;

        cin >> x >> y >> z;

        v.push_back({x, y, z});

        parent[i] = i;
    }

    // pq에 행성 간 거리 구해서 삽입
    // x축, y축, z축 따로 => O(3N)
    for(int d = 0; d < 3; d++)
    {
        vector<pair<int, int>> tmp;

        int val = 0;
        for(int i = 0; i < n; i++)
        {
            if(d == 0) val = get<0>(v[i]);
            else if(d == 1) val = get<1>(v[i]);
            else if(d == 2) val = get<2>(v[i]);

            tmp.push_back({val, i});
        }

        // 해당 축 오름차순 정렬
        sort(tmp.begin(), tmp.end());

        // 오름차순 했으니 해당 정점과 가장 가까운 정점은 인접한 정점 밖에 없음
        for(int i = 0; i < n - 1; i++)
        {
            auto [curVal, cur] = tmp[i];
            auto [nxtVal, nxt] = tmp[i+1];
            
            pq.push({abs(curVal - nxtVal), cur, nxt});
        }
    }

    int cnt = 0;
    int ans = 0;
    
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

    cout << ans << "\n";


    return 0;
}