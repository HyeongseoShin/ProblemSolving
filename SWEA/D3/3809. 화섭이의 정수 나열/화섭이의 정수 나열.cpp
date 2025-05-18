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

        char nums[1001];

        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int ans = 0;
        while(true)
        {
            string strAns = to_string(ans);

            bool isPossible = false;
            for(int i = 0; i <= n - (int)strAns.length(); i++)
            {
                int idx = 0;

                while(idx < strAns.length() && nums[i + idx] == strAns[idx]) idx++;

                if(idx == strAns.length())
                {
                    isPossible = true;
                    break;
                }
            }

            if(!isPossible) break;
            ans++;
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}