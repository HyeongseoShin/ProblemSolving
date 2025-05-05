#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int t = 1; t <= 10; t++)
    {
        int n;
        
        cin >> n;
        
        int board[100][100];
        
        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n;j++)
            {
        		cin >> board[i][j];        
            }    
        }
        
        int ans = 0;
        int prev = 0;
        for(int i = 0; i < n; i++)
        {
            prev = 0;
            for(int j = 0; j < n; j++)
            {
                if(board[j][i] == 1) prev = 1;
                else if(board[j][i] == 2 && prev == 1)
                {
                    prev = 2;
                    ans++;
                }
            }
        }
        
        
       
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}