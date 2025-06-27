#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

vector<ll> v;
tuple<int, int, int> ans;

ll result = LLONG_MAX;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n - 2; i++)
    {
        int st = i + 1;
        int en = n - 1;

        while(st < en)
        {
            ll tmp = v[i] + v[st] + v[en];

            if(abs(tmp) < abs(result))
            {
                ans = {v[i], v[st], v[en]};
                result = tmp;
            }
            
            if(tmp < 0) st++;
            else en--;
        }
    }

    auto [first, second, third] = ans;

    cout << first << " " << second << " " << third << "\n";

    return 0;
}