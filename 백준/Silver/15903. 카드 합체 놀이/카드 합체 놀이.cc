#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

priority_queue<ll, vector<ll>, greater<>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        pq.push(x);
    }

    while(m--)
    {
        ll x = pq.top();
        pq.pop();

        ll y = pq.top();
        pq.pop();

        ll z = x + y;
        pq.push(z);
        pq.push(z);
    }

    ll ans = 0;
    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << "\n";


    return 0;
}