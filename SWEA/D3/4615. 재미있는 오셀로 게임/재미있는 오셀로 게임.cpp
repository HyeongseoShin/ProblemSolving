#include <bits/stdc++.h>

using namespace std;

int board[10][10];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int cnt[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {
        int n, m;
        cin >> n >> m;
        
        memset(board, 0, sizeof(board));
        
        board[n/2][n/2] = 2;
        board[n/2][n/2 + 1] = 1;
        board[n/2 + 1][n/2] = 1;
        board[n/2 + 1][n/2 + 1] = 2;
        
		fill(cnt, cnt + 3, 0);
        
        cnt[1] = 2;
        cnt[2] = 2;
        
        while(m--)
        {
            int x, y, player;
            cin >> y >> x >> player;
            
            if(board[x][y] != 0) continue;
            
            board[x][y] = player;
            cnt[player]++;
            
            for(int dir = 0; dir < 8; dir++)
            {
                int nX = x + dx[dir];
                int nY = y + dy[dir];
                
                int step = 0;
                while(nX >= 1 && nX <= n && nY >= 1 && nY <= n && board[nX][nY] != 0 && board[nX][nY] != player)
                {
                    // cnt[board[nX][nY]]--;
                    // board[nX][nY] = player;
                    // cnt[board[nX][nY]]++;
                    
                    nX += dx[dir];
                    nY += dy[dir];
                    step++;
                }
                
                if(nX >= 1 && nX <= n && nY >= 1 && nY <= n && board[nX][nY] == player)
                {
                    while(step--)
                    {
                        nX -= dx[dir];
                        nY -= dy[dir];
                        
                        cnt[board[nX][nY]]--;
                    	board[nX][nY] = player;
                    	cnt[board[nX][nY]]++;
                    }
                }
            }
        }
        
        cout << "#" << t << " " << cnt[1] << " " << cnt[2] << "\n";
        
    }
    return 0;
}