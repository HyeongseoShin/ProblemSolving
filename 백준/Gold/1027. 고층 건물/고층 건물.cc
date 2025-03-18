#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> v;

vector<int> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    v.resize(n);
    ans.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(int i = 0; i < n; i++)
    {
        double maxVal = -1000000000;

        for(int j = i + 1; j < n; j++)
        {
            double curVal = (v[j] - v[i]) * 1.0 / (j - i);

            if(maxVal < curVal)
            {
                maxVal = curVal;
                ans[i]++;
                ans[j]++;
            }
        }
    }

    cout << *max_element(ans.begin(), ans.end()) << "\n";

    return 0;
}