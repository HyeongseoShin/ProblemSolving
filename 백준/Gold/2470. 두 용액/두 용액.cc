#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

pair<int, int> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int st = 0;
    int en = n - 1;

    ans = {1000000000, 1000000000};

    while(st < en)
    {
        if(abs(v[st] + v[en]) < abs(ans.first + ans.second))
        {
            ans = {v[st], v[en]};
        }

        if(v[st] + v[en] > 0) en--;
        else if(v[st] + v[en] < 0) st++;
        else break;
    }

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}