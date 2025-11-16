#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

vector<int> v;
vector<int> diff;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for(int i = 1; i < n; i++)
    {
        diff.push_back(v[i] - v[i-1]);
    }

    sort(diff.begin(), diff.end());

    int ans = 0;
    for(int i = 0; i < (int)diff.size() - (k - 1); i++)
    {
        ans += diff[i];
    }

    cout << ans << "\n";
    return 0;
}