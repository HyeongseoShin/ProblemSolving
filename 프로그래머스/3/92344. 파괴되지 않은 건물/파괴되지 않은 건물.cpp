#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans = 0;
int diff[1005][1005];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    n = (int)board.size();
    m = (int)board[0].size();
    
    for(int k = 0; k < (int)skill.size(); k++)
    {
        int type = skill[k][0];
        int r1 = skill[k][1];
        int c1 = skill[k][2];
        int r2 = skill[k][3];
        int c2 = skill[k][4];
        int degree = skill[k][5];
        
        if(type == 1) degree *= -1;
        
        diff[r1][c1] += degree;
        diff[r2 + 1][c1] -= degree;
        diff[r1][c2 + 1] -= degree;
        diff[r2 + 1][c2 + 1] += degree;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            diff[i][j] += diff[i][j-1];
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            diff[j][i] += diff[j-1][i];
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            board[i][j] += diff[i][j];
            if(board[i][j] > 0) ans++;
        }
    }
    
    return ans;
}