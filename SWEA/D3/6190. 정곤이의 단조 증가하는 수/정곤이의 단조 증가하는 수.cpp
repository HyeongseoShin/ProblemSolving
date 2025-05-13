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

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int tmp = v[i] * v[j];
                
                bool isPossible = true;
                while(tmp / 10)
                {
                    if((tmp % 10) < ((tmp / 10) % 10))
                    {
                        isPossible = false;
                        break;
                    }

                    tmp /= 10;
                }

                if(isPossible) ans = max(ans, v[i] * v[j]);
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }
}