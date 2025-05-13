#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n;
        cin >> n;

        vector<int> v;

        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            v.push_back(x);
        }

        // sort(v.begin(), v.end(), greater<>());

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                string tmp = to_string(v[i] * v[j]);
                
                bool isPossible = true;
                for(int i = 1; i < (int)tmp.length(); i++)
                {
                    if(tmp[i-1] > tmp[i])
                    {
                        isPossible = false;
                        break;
                    }
                }

                if(isPossible) ans = max(ans, v[i] * v[j]);
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }
}