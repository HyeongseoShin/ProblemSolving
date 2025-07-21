#include <bits/stdc++.h>

using namespace std;

int n; // 사람 수
int d; // 철로 길이

// <집, 사무실>
vector<pair<int, int>> v;

int ans = 0;

// 도착점 기준으로 정렬
bool cmp(pair<int, int> A, pair<int, int> B)
{
    if(A.second == B.second) return A.first < B.first;
    else return A.second < B.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int h, o;
        cin >> h >> o;

        if(h > o) swap(h, o);

        v.push_back({h, o});
    }

    cin >> d;

    sort(v.begin(), v.end(), cmp);

    priority_queue<int, vector<int>, greater<>> pq;

    for(auto [st, en] : v)
    {
        if(en - st > d) continue;

        pq.push(st);

        
        while(!pq.empty() && pq.top() < en - d) pq.pop();
        ans = max(ans, (int)pq.size());
    }

    cout << ans << "\n";


    return 0;
}