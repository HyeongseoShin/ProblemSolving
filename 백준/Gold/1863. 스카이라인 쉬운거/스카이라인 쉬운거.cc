#include <bits/stdc++.h>

using namespace std;

int n;

stack<int> stk;

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

   for(int i = 0; i <= n; i++)
   {
        int x, y;

        if(i < n) cin >> x >> y;
        else y = 0;
        

        while(!stk.empty() && stk.top() >= y)
        {
            if(stk.top() > y) ans++;
            stk.pop();
        }

        stk.push(y);
    }

    cout << ans << "\n";

    return 0;
}