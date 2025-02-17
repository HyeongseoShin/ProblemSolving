#include <bits/stdc++.h>

using namespace std;

int n;

string tmp, from, to;

int ans = INT_MAX;

void TurnLight(int idx)
{
    for(int i = -1; i <= 1; i++)
    {
        if(idx + i >= 0 && idx + i < n)
        {
            tmp[idx + i] = (tmp[idx + i] == '0' ? '1' : '0');
        }
    }
}

void Solve(bool isFirstOn)
{
    tmp = from;
    int cnt = 0;

    if(isFirstOn)
    {
        tmp[0] = (tmp[0] == '0' ? '1' : '0');
        tmp[1] = (tmp[1] == '0' ? '1' : '0');
        cnt++;
    }
    
    for(int i = 1; i < n; i++)
    {
        if(tmp[i-1] != to[i-1])
        {
            TurnLight(i);
            cnt++;
        }
    }

    

    if(tmp == to) ans = min(ans, cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> from >> to;

    Solve(true);
    Solve(false);

    if(ans == INT_MAX) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}