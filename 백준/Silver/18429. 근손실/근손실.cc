#include <bits/stdc++.h>

using namespace std;

int n, k;

int board[10];
bool isUsed[10];
int ans = 0;

void GetAns(int cnt, int cur)
{
    // cout << "cnt: " << cnt << " cur: " << cur << "\n";
    if(cnt == n)
    {
        if(cur >= 500) ans++;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(isUsed[i]) continue;
        if(cur - k + board[i] < 500) continue;

        isUsed[i] = true;
        GetAns(cnt+1, cur - k + board[i]);
        isUsed[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    GetAns(0, 500);

    cout << ans << "\n";

    return 0;
}