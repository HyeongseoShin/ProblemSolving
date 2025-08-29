#include <bits/stdc++.h>

using namespace std;

int n;

// <데드라인, 컵라면 수>
vector<pair<int, int>> v;

// 컵라면 수 minHeap
priority_queue<int, vector<int>, greater<>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int day, cnt;
        cin >> day >> cnt;

        v.push_back({day, cnt});
    }

    // 데드라인 순으로 정렬
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        auto [day, cnt] = v[i];
        pq.push(cnt);

        if((int)pq.size() > day) pq.pop();
    }

    int ans = 0;
    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << "\n";

    return 0;
}