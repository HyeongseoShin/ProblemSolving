#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

// 가방의 최대 수용 무게
// 가방에는 최대 하나의 보석만
vector<ll> bags;

// 보석 (무게, 가격)
vector<pair<ll, ll>> jewels;

struct cmp
{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        if(a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    }
};

// 보석 (무게, 가격) => 비싸고, 가벼운 순으로 정렬
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        ll m, v;

        cin >> m >> v;

        jewels.push_back({m, v});
    }
    
    for(int i = 0; i < k; i++)
    {
        ll c;
        cin >> c;

        bags.push_back(c);
    }

    sort(bags.begin(), bags.end());
    sort(jewels.begin(), jewels.end()); // 가벼운 순으로 보석 정렬

    ll ans = 0;
    int idx = 0;
    for(int i = 0; i < k; i++)
    {
        while(idx < n && bags[i] >= jewels[idx].first)
        {
            pq.push(jewels[idx++]);
        }

        if(!pq.empty())
        {
            ans += pq.top().second;
            pq.pop();
        } 

    }
            
    cout << ans << "\n";

    return 0;
}