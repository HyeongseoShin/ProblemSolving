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
        string s;
        cin >> s;

        queue<int> q;

        for(auto c : s)
        {
            q.push(c - '0');
        }

        int ans = 0;

        while(true)
        {
            if(q.size() == 1)
            {
                ans = q.front();
                break;
            }

            int sum = 0;
            while(!q.empty())
            {
                sum += q.front();
                q.pop();
            }

            string strSum = to_string(sum);

            for(auto c : strSum)
            {
                q.push(c - '0');
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}