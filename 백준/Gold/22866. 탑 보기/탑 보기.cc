// 스택
// 오 -> 왼 순회 : 나보다 오른쪽에 있는 건물들 중 볼 수 있는 건물
// 왼 -> 오 순회 : 나보다 왼쪽에 있는 건물들 중 볼 수 있는 건물
#include <bits/stdc++.h>

using namespace std;

int n, l;

int buildings[100001];

int near[100001];
int cnt[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> buildings[i];
    }

    // 오 -> 왼 순회
    stack<int> stk;

    for(int i = n; i >= 1; i--)
    {
        while(!stk.empty() && buildings[i] >= buildings[stk.top()])
        {
            stk.pop();
        }

        if(!stk.empty())
        {
            near[i] = stk.top();
            cnt[i] = stk.size();
        }
        
        stk.push(i);
    }

    // 스택 초기화
    while(!stk.empty())
    {
        stk.pop();
    }

    //  왼 -> 오 순회
    for(int i = 1; i <= n; i++)
    {
        while(!stk.empty() && buildings[i] >= buildings[stk.top()])
        {
            stk.pop();
        }

        if(!stk.empty())
        {
            if(abs(i - stk.top()) <= abs(i - near[i]))
            {
                near[i] = stk.top();
            }
            
            cnt[i] += stk.size();
        }
        
        stk.push(i);
    }

    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == 0) cout << cnt[i] << "\n";
        else cout << cnt[i] << " " << near[i] << "\n";
    }

    return 0;
}