#include <bits/stdc++.h>

using namespace std;

char board[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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
        
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for(int j = 0; j < m; j++)
            {
                board[i][j] = s[j];
            }
        }
        
        bool isPossible = true;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m;j++)
            {
                isPossible = true;
                for(int k = 0; k < 4; k++)
                {
                    int nX = i + dx[k];
                    int nY = j + dy[k];
                    
                    if(nX < 0 || nX >= n || nY < 0 || nY>= m) continue;
                    if(board[i][j] != '?' && board[nX][nY] != '?' && board[i][j] == board[nX][nY])
                    {
                        isPossible = false;
                        break;
                    }
                    
                    if(board[i][j] == '?' && board[nX][nY] != '?')
                    {
                        board[i][j] = (board[nX][nY] == '#') ? '.' : '#';
                        break;
                    }
                }
                if(!isPossible) break;
                // if(board[i][j] == '?') board[i][j] = '#';
            }
            if(!isPossible) break;
        }
        
        cout << "#" << t << " ";
        if(isPossible) cout << "possible\n";
        else cout << "impossible\n";
    }
    return 0;
}