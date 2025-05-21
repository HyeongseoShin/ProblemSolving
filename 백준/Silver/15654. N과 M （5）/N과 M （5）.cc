#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v;
bool isUsed[8];
vector<int> tmp;

void GetAns()
{
    if(tmp.size() == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << tmp[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(isUsed[i]) continue;
        isUsed[i] = true;
        tmp.push_back(v[i]);
        GetAns();
        tmp.pop_back();
        isUsed[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    sort(v.begin(), v.end());

    tmp.clear();
    GetAns();
    return 0;
}