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
        int n;
        
        cin >> n;
        
        int board[50][50];
        
        for(int i = 0; i < n;i++)
        {
            string s;
            cin >> s;
            
            for(int j = 0; j < n; j++)
            {
                board[i][j] = s[j] - '0';
            }
        }
        
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i <= n / 2; i++)
        {
            for(int j = n / 2 - cnt; j <= n / 2 + cnt; j++)
            {
                ans += board[i][j];
            }
            cnt++;
        }
        
        cnt = n / 2 - 1;
        for(int i = n/2 + 1; i < n; i++)
        {
            for(int j = n / 2 - cnt; j <= n / 2 + cnt; j++)
            {
                ans += board[i][j];
            }
            cnt--;
        }
        
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}