#include <bits/stdc++.h>

using namespace std;

int n;

int col[10];
int ld[20];
int rd[20];

int ans = 0;

void GetAns(int x)
{
    if(x == n)
    {
        ans++;
        return ;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(col[i] == 1) continue;
        if(ld[x + i] == 1) continue;
        if(rd[n - (i - x) - 1] == 1) continue;

        col[i] = 1;
        ld[x + i] = 1;
        rd[n - (i - x) - 1] = 1;

        GetAns(x+1);

        col[i] = 0;
        ld[x + i] = 0;
        rd[n - (i - x) - 1] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {        
        cin >> n;
        
        fill(col, col + 10, 0);
        fill(ld, ld + 20, 0);
        fill(rd, rd + 20, 0);
        
        ans = 0;
        
        GetAns(0);
        
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}