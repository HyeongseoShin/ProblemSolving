#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> lis;
vector<int> v;
vector<int> idx;
vector<int> ans;

int GetPos(int target)
{
    int st = 0;
    int en = lis.size() - 1;
    int mid;

    while(st < en)
    {
        mid = (st + en) / 2;
        
        if(target > lis[mid]) st = mid + 1;
        else en = mid;
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

    for(int i = 0; i < n; i++)
    {
        if(lis.empty() || lis.back() < v[i])
        {
            lis.push_back(v[i]);
            idx[i] = lis.size() - 1;
        }

        else
        {
            int pos = GetPos(v[i]);
            lis[pos] = v[i];
            idx[i] = pos;
        }
    }

    cout << lis.size() << "\n";

    int cur = lis.size() - 1;

    for(int i = (int)idx.size() - 1; i >= 0; i--)
    {
        if(cur == idx[i])
        {
            ans.push_back(v[i]);
            cur--;
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