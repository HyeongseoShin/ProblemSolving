#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> v;
vector<int> lis;

void FindPos(int target)
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

    lis[en] = target;
}

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

    lis.push_back(v[0]);

    for(int i = 1; i < n; i++)
    {
        if(lis.back() >= v[i]) FindPos(v[i]);
        else lis.push_back(v[i]);
    }

    cout << lis.size() << "\n";

    return 0;
}