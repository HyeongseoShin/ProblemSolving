#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v;

int vSize;

vector<int> result;

void GetAns(int idx, int cnt)
{
    if(cnt == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";

        return;
    }

    for(int i = idx; i < vSize; i++)
    {
        result.push_back(v[i]);
        GetAns(i, cnt + 1);
        result.pop_back();
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
    v.erase(unique(v.begin(), v.end()), v.end());
    

    vSize = (int)v.size();

    GetAns(0, 0);

    return 0;
}