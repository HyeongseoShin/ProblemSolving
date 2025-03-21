#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m;

tuple<ll, ll, ll> edges[6005];

bool isCycle = false;

ll dst[6005];

void GetAns(ll cnt)
{
    dst[1] = 0;

    // n - 1 만큼 반복
    for(ll i = 0; i < n - 1; i++)
    {
        for(ll i = 0; i < m; i++)
        {
            auto [s, e, w] = edges[i];
            if(dst[s] != LLONG_MAX && dst[e] > dst[s] + w)
            {
                dst[e] = dst[s] + w;

                if(cnt == 1)
                {
                    isCycle = true;
                    break;
                }
            }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for(ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        edges[i] = {a, b, c};
    }

    fill(dst, dst + n + 1, LLONG_MAX);
    GetAns(0);

    GetAns(1);

    if(isCycle) cout << "-1\n";

    else
    {
        for(ll i = 2; i <= n; i++)
        {
            if(dst[i] == LLONG_MAX) cout << "-1\n";
            else cout << dst[i] << "\n";
        }
    }



    

    return 0;
}