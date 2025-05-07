#include <bits/stdc++.h>

using namespace std;

int n;

int histogram[100002];

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    stack<int> stk;

    for(int i = 1; i <= n; i++)
    {
        cin >> histogram[i];
    }

    stk.push(0);

    // histogram[n+1] = 0이라서 나머지 스택에 있는 거 다 pop()됨
    for(int i = 1; i <= n + 1; i++)
    {
        while(!stk.empty() && histogram[stk.top()] > histogram[i])
        {
            int cur = stk.top();
            stk.pop();
            
            ans = max(ans, histogram[cur] * (i - stk.top() - 1));
        }

        stk.push(i);
    }

    cout << ans << "\n";

    return 0;
}