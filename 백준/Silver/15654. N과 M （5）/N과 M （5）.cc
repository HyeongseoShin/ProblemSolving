#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v;
bool isUsed[8];

void GetAns(vector<int> tmp)
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
        GetAns(tmp);
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

    fill(isUsed, isUsed + 8, false);

    vector<int> tmp;
    GetAns(tmp);
    return 0;
}