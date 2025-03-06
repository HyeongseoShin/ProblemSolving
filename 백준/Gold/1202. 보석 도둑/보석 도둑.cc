#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

// (무게, 가격)
vector<pair<int, int>> jewels;
vector<int> bags;

struct cmp
{
    bool operator() (pair<int, int> A, pair<int, int> B)
    {
        if(A.second != B.second) return A.second < B.second;
        else return A.first > B.first;
    }
    
};

// pq ==> 비싸고 가벼운 순으로 정렬
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        int m, v;

        cin >> m >> v;
        jewels.push_back({m, v});
    }

    for(int i = 0; i < k; i++)
    {
        int w;
        cin >> w;

        bags.push_back(w);
    }

    // 가방 : 가벼운 순으로 정렬
    sort(bags.begin(), bags.end());

    // 보석 : 가벼운 순으로 정렬
    sort(jewels.begin(), jewels.end());

    ll ans = 0;
    int idx = 0;

    for(int i = 0; i < k; i++)
    {
        // 현재 가방에 담을 수 있으면 pq에 삽입
        while(idx < n && bags[i] >= jewels[idx].first)
        {
            pq.push(jewels[idx++]);
        }

        // 큐가 비어있지 않다면 현재 가방에서 담을 수 있는 가장 비싼 보석은 top
        if(!pq.empty())
        {
            ans += pq.top().second;
            pq.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}