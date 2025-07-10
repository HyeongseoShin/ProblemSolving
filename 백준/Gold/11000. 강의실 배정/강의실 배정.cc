#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int>> v;

priority_queue<int, vector<int>, greater<>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int st, en;
        cin >> st >> en;

        v.push_back({st, en});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        auto [st, en] = v[i];

        if(!pq.empty() && pq.top() <= st) pq.pop();
        pq.push(en);

    }

    cout << (int)pq.size() << "\n";

    return 0;
}