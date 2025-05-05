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
        
        char board[8][8];
        
        for(int i = 0; i < 8; i++)
        {
            string s;
            cin >> s;
            
            for(int j = 0; j < 8; j++)
            {
                board[i][j] = s[j];
            }
        }
        
        
        int x = 0;
        int y = 0;
        
        int ans = 0;
        while(x < 8)
        {
            int stX = x;
            int stY = y;
            
            int enX = x + n - 1;
            int enY = y;

            while(stX <= enX && enX < 8 && board[stX][stY] == board[enX][enY])
            {
                stX++;
                enX--;
            }
            
            if(stX >= enX && board[stX][stY] == board[enX][enY])
            {
                ans++;
            }
            
			// 가로 검사
            stX = x;
            stY = y;
            
            enX = x;
            enY = y + n - 1;
            
            while(stY <= enY && enY < 8 && board[stX][stY] == board[enX][enY])
            {
                stY++;
                enY--;
            }
            
            if(stY >= enY && board[stX][stY] == board[enX][enY])
            {
                ans++;
            }
            
            y++;
            
            if(y == 8)
            {
                x++;
                y = 0;
            }
        }
        
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}