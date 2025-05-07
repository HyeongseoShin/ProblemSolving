#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

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
        
        vector<string> board;
        
        bool isPossible = false;
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            
            board.push_back(s);
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == '.') continue;
                
                for(int dir = 0; dir < 8; dir++)
                {
                    int cnt = 1;
                
                    int nX = i + dx[dir];
                    int nY = j + dy[dir];
                    
                    while(nX >= 0 && nX < n && nY >= 0 && nY < n && board[nX][nY] == 'o')
                    {
                        cnt++;
                        nX += dx[dir];
                        nY += dy[dir];

                    }
                    
                    if(cnt >= 5)
                    {
                        isPossible = true;
                        break;
                    }
                }
                
                if(isPossible) break;
            }
            
            if(isPossible) break;
        }
        
        cout << "#" << t << " ";
        if(isPossible) cout << "YES\n";
        else cout << "NO\n";
        
    }
    return 0;
}