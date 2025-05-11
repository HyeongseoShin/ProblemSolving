#include <bits/stdc++.h>

using namespace std;

char board[20][20];

int h, w;

int pX, pY;

void Shoot()
{
    int dx, dy;
    switch(board[pX][pY])
    {
        case '^':
            dx = -1;
            dy = 0;
            break;
            
        case 'v':
            dx = 1;
            dy = 0;
            break;
            
        case '<':
            dx = 0;
            dy = -1;
            break;
            
        case '>':
            dx = 0;
            dy = 1;
            break;
    }
    
    int nX = pX + dx;
    int nY = pY + dy;
    
    while(true)
    {
        if(nX < 0 || nX >= h || nY < 0 || nY >= w) break;
        if(board[nX][nY] != '.' && board[nX][nY] != '-') break;
        
        nX += dx;
        nY += dy;
    }
    
    if(nX < 0 || nX >= h || nY < 0 || nY >= w) return;
    if(board[nX][nY] != '*') return;
    
    board[nX][nY] = '.';
}

void Move(char dir)
{
    int nX, nY;
    char nxtDir;
    
	if(dir == 'U')
    {
        nxtDir = '^';
        
        nX = pX - 1;
        nY = pY;   
    }
    
   	else if(dir == 'D')
    {
        nxtDir = 'v';
        
        nX = pX + 1;
        nY = pY;   
    }
    
    else if(dir == 'L')
    {
        nxtDir = '<';
        
        nX = pX;
        nY = pY - 1;   
    }
    
    else if(dir == 'R')
    {
        nxtDir = '>';
        
        nX = pX;
        nY = pY + 1;   
    }
    
    board[pX][pY] = nxtDir;
    
    if(nX < 0 || nX >= h || nY < 0 || nY >= w) return;
    if(board[nX][nY] != '.') return;
    
    board[pX][pY] = '.';
    pX = nX;
    pY = nY;
    board[pX][pY] = nxtDir;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {
        cin >> h >> w;
        
        for(int i = 0; i < h; i++)
        {
            string s;
            cin >> s;
            
            for(int j = 0; j < w; j++)
            {
                board[i][j] = s[j];
                
                if(board[i][j] == '<' || board[i][j] == '^' || board[i][j] == '>' || board[i][j] == 'v')
                {
                    pX = i;
                    pY = j;
                }
            }
        }
        
        int n;
        cin >> n;
        
        string op;
        cin >> op;
        
        for(int i = 0; i < n; i++)
        {
            if(op[i] == 'S') Shoot();
            else Move(op[i]);
        }
        
        cout << "#" << t << " ";
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}