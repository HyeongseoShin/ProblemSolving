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
        int k;
        cin >> k;

        int n = pow(2, k);

        queue<int> q;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            q.push(x);
        }

        ll ans = 0;

        while(q.size() >= 2)
        {
            int first = q.front();
            q.pop();

            int second = q.front();
            q.pop();

            ans += abs(first - second);

            int winner = max(first, second);
            q.push(winner);
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}