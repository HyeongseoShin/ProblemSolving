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
        
        int row[100];
        int col[100];
        
        int ld = 0;
        int rd = 0;
        
        fill(row, row + 100, 0);
        fill(col, col + 100, 0);
        
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                int x;
                cin >> x;
                
                row[i] += x;
                col[j] += x;
                
                if(i == j) rd += x;
                if(i + j == 99) ld += x;
            }
        }
        
        int maxRow = *max_element(row, row + 100);
        int maxCol = *max_element(col, col + 100);
        
        int ans = max({maxRow, maxCol, ld, rd});
        
        cout << "#" << n << " " << ans << "\n";
        
        
    }
    return 0;
}