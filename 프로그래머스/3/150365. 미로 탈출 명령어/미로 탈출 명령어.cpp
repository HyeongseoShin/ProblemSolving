#include <bits/stdc++.h>

using namespace std;

// 하 좌 우 상
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

string dir[4] = {"d", "l", "r", "u"};

int N, M;
int goalX, goalY;
string ans = "";

// vis[i][j][k] : (i, j)까지 오는데 k번만에 온적이 있는지
bool vis[51][51][2501];

bool isFinished = false;

void DFS(int x, int y, int k, string cur)
{
    if(isFinished) return;
    
    if(x == goalX && y == goalY && k == 0)
    {
        ans = cur;
        isFinished = true;
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];
        
        if(nX < 0 || nX >= N || nY < 0 || nY >= M) continue;
        if(vis[nX][nY][k-1]) continue;
        if(k-1 < 0) continue;
        
        vis[nX][nY][k-1] = true;
        DFS(nX, nY, k-1, cur + dir[i]);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {    
    
    N = n, M = m;
    goalX = r-1, goalY = c-1;
    
    DFS(x-1, y-1, k, "");
    
    if(ans == "") ans = "impossible";
    return ans;
}