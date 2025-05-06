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
        
        char board[100][100];
        
        for(int i = 0; i < 100; i++)
        {
            string s;
            cin >> s;
            
            for(int j = 0; j < 100; j++)
            {
                board[i][j] = s[j];
            }
        }
        
        int ans = 1;
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                for(int k = 99; k > j; k--)
                {
            		int st = j;
                    int en = k;

                    while(st <= en && board[i][st] == board[i][en])
                    {
                        st++;
                        en--;
                    }
                    
                    if(board[i][st] == board[i][en]) ans = max(ans, k - j + 1);
                }
                
                
                for(int k = 99; k > i; k--)
                {
            		int st = i;
                    int en = k;
                    
                    while(st <= en && board[st][j] == board[en][j])
                    {
                        st++;
                        en--;
                    }
                    
                    if(board[st][j] == board[en][j]) ans = max(ans, k - i + 1);
                }
                
            }
        }
            
        cout << "#" << n << " " << ans << "\n";
    }
    return 0;
}