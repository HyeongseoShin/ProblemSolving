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

        stack<int> stk;

        for(int i = 0; i < k; i++)
        {
            int x;
            cin >> x;

            if(x == 0) stk.pop();
            else stk.push(x);
        }

        ll sum = 0;

        while(!stk.empty())
        {
            sum += stk.top();
            stk.pop();
        }

        cout << "#" << t << " " << sum << "\n";
    }

    return 0;
}