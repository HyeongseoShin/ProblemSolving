#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll ans = -1;

vector<ll> nums;

void dfs(ll cur, ll last)
{
    nums.push_back(cur);

    for(ll nxt = 0; nxt < last; nxt++)
    {
        dfs(cur * 10 + nxt, nxt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(ll i = 0; i <= 9; i++)
    {
        dfs(i, i);
    }

    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    sort(nums.begin(), nums.end());

    if((int)nums.size() > n) ans = nums[n];
    cout << ans << "\n";

    return 0;
}