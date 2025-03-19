#include <bits/stdc++.h>

using namespace std;

int n, d, k, c;

vector<int> v;

int sushi [4000];

int ans = 0;

bool isCouponInBelt = false;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;

    v.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        
        if(v[i] == c) isCouponInBelt = true;
    }

    int st = 0;
    int en = 0;

    int sz = 0;
    int cur = 0;

    while(st < n)
    {
        while(sz < k)
        {
            // 새로운 초밥이면 가짓 수++
            if(sushi[v[en]] == 0) cur++;
            sushi[v[en]]++;
            en = (en + 1) % n;
            sz++;
        }

        // if(v[c] == 0 && ((st > 0 && v[st-1] == c) || v[(en + 1) % n] == c))
        // {
        //     ans = max (ans, cur+1);
        // }

        // cout << "st : " << st << " en: " << en << " sz: " << sz << "\n";
        // if(sushi[c] == 0 && (v[st-1] == c || v[en] == c))
        // {
        //     ans = max(ans, cur + 1);
        // }

        // else ans = max(ans, cur);

        if(isCouponInBelt && sushi[c] == 0)
        {
            ans = max(ans, cur + 1);
        }
        else
        {
            ans = max(ans, cur);
        }

        sushi[v[st]]--;
        if(sushi[v[st]] == 0) cur--;
        st++;
        sz--;
        
    }

    if(!isCouponInBelt) ans++;

    cout << ans << "\n";

    return 0;
}