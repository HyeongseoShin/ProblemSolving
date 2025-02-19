// https://www.acmicpc.net/problem/2110

#include <bits/stdc++.h>

using namespace std;

int n, c;

vector<int> v;

long long ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        v.push_back(x);
    }

    sort(v.begin(), v.end());
    
    long long st = 1;
    long long en = v[n-1] - v[0];
    long long mid;

    while(st <= en)
    {
        mid = (st + en) / 2;
        int cnt = 0;
        int pos = 0;

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                pos = i;
                cnt++;
            }
            else if(v[i] - v[pos] >= mid)
            {
                pos = i;
                cnt++;
            }

            if(cnt >= c) break;
        }

        if(cnt >= c)
        {
            ans = max(ans, mid);
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }
    
    cout << ans << "\n";

    return 0;
}