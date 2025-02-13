// https://www.acmicpc.net/problem/2467
#include <bits/stdc++.h>

using namespace std;

int n;

vector<long long> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    v.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    pair<int, int> ans = {0, 0};
    long long minVal = LLONG_MAX;

    int st = 0;
    int en = n - 1;

    while(st < en)
    {
        int cur = abs(v[st] + v[en]);

        if(cur < minVal)
        {
            ans = {v[st], v[en]};
            minVal = cur;
        }

        if(v[st] + v[en] > 0)
        {
            en--;
        }
        else if(v[st] + v[en] < 0)
        {
            st++;
        }
        else
        {
            break;
        }
    }

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}