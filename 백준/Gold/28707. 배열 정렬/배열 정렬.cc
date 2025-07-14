#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> A;

vector<tuple<int, int, int>> edges;

// <배열 상태, 비용 합> : 해당 배열 상태가 되기 위한 최소 비용 저장
map<vector<int>, int> dist;

// 다익스트라로 해당 배열 상태가 되기 위한 최소 비용합 구하기
void Dijkstra()
{
    // pq : <비용, 배열상태>
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;

    dist[A] = 0;

    pq.push({dist[A], A});

    while(!pq.empty())
    {
        auto [curC, curA] = pq.top();
        pq.pop();

        for(auto [l, r, c] : edges)
        {
            vector<int> tmpA = curA;
            swap(tmpA[l], tmpA[r]);

            if(dist.count(tmpA) == 0 || dist[tmpA] > curC + c)
            {
                dist[tmpA] = curC + c;
                pq.push({dist[tmpA], tmpA});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        A.push_back(x);
    }

    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int l, r, c;

        cin >> l >> r >> c;

        edges.push_back({l - 1, r - 1, c});
    }

    Dijkstra();

    sort(A.begin(), A.end());

    int ans = 0;
    if(dist.count(A) == 0) ans = -1;
    else ans = dist[A];

    cout << ans << "\n";


    return 0;
}