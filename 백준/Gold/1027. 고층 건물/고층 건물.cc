#include <bits/stdc++.h>

using namespace std;

int n;

int ans = 0;

vector<int> v;

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

    for(int i = 0; i < n; i++)
    {
        int cur = 0;

        double tmp = 0;

        for(int j = i - 1; j >= 0; j--)
        {
            if(j == i - 1 || tmp > (double)(v[i] - v[j]) / (i - j))
            {
                cur++;
                tmp = (double)(v[i] - v[j]) / (i - j);
            }
        }

        tmp = 0;

        for(int j = i + 1; j < n; j++)
        {
            if(j == i + 1 || tmp < (double)(v[j] - v[i]) / (j - i))
            {
                cur++;
                tmp = (double)(v[j] - v[i]) / (j - i);
            }
        }

        ans = max(ans, cur);
    }

    cout << ans << "\n";


    return 0;
}