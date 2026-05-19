#include <bits/stdc++.h>

using namespace std;

int dx[10] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[10] = {0, 0, -1, 1, -1, 1, -1, 1};

bool isPossible(int x, int y, int k, vector<vector<string>>& places)
{
    for(int i = 0; i < 4; i++)
    {
        int nX = x;
        int nY = y;
        
        for(int j = 0; j < 2; j++)
        {
            nX += dx[i];
            nY += dy[i];
            
            if(nX < 0 || nX >= 5 || nY < 0 || nY >= 5) break;
            
            if(places[k][nX][nY] == 'P') return false;
            if(places[k][nX][nY] == 'X') break;
        }
    }
    
    for(int i = 4; i < 8; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];
        
        if(nX < 0 || nX >= 5 || nY < 0 || nY >= 5) continue;
        
        if(places[k][nX][nY] == 'P')
        {
            if(places[k][x][nY] != 'X' || places[k][nX][y] != 'X') return false;
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int k = 0; k < 5; k++)
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(places[k][i][j] != 'P') continue;
                
                if(!isPossible(i, j, k, places))
                {
                    answer.push_back(0);
                    break;
                }
            }
            
            if((int)answer.size() != k) break;
        }
        
        if((int)answer.size() == k) answer.push_back(1);
    }
    return answer;
}