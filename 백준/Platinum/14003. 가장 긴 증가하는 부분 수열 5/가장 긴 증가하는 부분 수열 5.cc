#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> v;
vector<int> lis;
vector<int> idx;
vector<int> ans;

int FindPos(int target)
{
    int st = 0;
    int en = lis.size() - 1;
    int mid;

    while(st < en)
    {
        mid = (st + en) / 2;

        if(lis[mid] >= target) en = mid;
        else st = mid + 1;
    }

    return en;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    v.resize(n);
    idx.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    lis.push_back(v[0]);
    idx[0] = 0;

    for(int i = 1; i < n; i++)
    {
        if(lis.back() >= v[i])
        {
            int pos = FindPos(v[i]);
            lis[pos] = v[i];
            idx[i] = pos;
        }

        else
        {
            lis.push_back(v[i]);
            idx[i] = lis.size() - 1;
        }
    }

    cout << lis.size() << "\n";

    int t = lis.size() - 1;

    for(int i = n-1; i >= 0; i--)
    {
        if(idx[i] == t)
        {
            ans.push_back(v[i]);
            t--;
        }
    }

    reverse(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}