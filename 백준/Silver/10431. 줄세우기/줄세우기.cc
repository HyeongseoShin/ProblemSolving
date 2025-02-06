// https://www.acmicpc.net/problem/10431

#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--)
    {
        int t;
        cin >> t;

        vector<int> v;
        int cnt = 0;

        for(int i = 0; i < 20; i++)
        {   
            int x;
            cin >> x;

            v.push_back(x);

            for(int j = 0; j < (int)v.size(); j++)
            {
                if(x < v[j])
                {
                    cnt += (int)v.size() - i;
                }
            }

            sort(v.begin(), v.end());
        }

        cout << t << " " << cnt << "\n";
    }

    return 0;
}