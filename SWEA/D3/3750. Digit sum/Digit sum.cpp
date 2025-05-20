#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        ll n;
        cin >> n;

        queue<int> q;

        while(n > 0)
        {
            q.push(n % 10);
            n /= 10;
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

            while(sum > 0)
            {
                q.push(sum % 10);
                sum /= 10;
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}