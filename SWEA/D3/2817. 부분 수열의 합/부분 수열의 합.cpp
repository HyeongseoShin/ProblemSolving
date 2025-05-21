#include <bits/stdc++.h>

using namespace std;

int n, k;
int board[20];
int ans = 0;

void GetAns(int idx, int cur)
{
    if(cur == k)
    {
        ans++;
        return;
    }

    for(int i = idx + 1; i < n; i++)
    {
        if(cur + board[i] <= k) GetAns(i, cur + board[i]);
    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
        {
            cin >> board[i];
        }

        ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            GetAns(i, board[i]);
        }
        

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}