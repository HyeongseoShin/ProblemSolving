#include <bits/stdc++.h>

using namespace std;

int pos[301][301];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int cur = 1;
    for(int i = 1; i <= 300; i++)
    {
        pos[i][1] = cur;
        for(int j = 2; j <= 300; j++)
        {
            pos[i][j] = pos[i][j - 1] + i + j - 1;
        }
        cur += i;
    }
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {
        int p, q;
        cin >> p >> q;        
        
        int pX, pY, qX, qY;
        
        for(int i = 1; i <= 300; i++)
        {
            for(int j = 1; j <= 300; j++)
            {
                if(pos[i][j] == p)
                {
                    pX = i;
                    pY = j;
                }
                
                if(pos[i][j] == q)
                {
                    qX = i;
                    qY = j;
                }
            }
        }
        
        cout << "#" << t << " " << pos[pX + qX][pY + qY] << "\n";
        
    }
    return 0;
}