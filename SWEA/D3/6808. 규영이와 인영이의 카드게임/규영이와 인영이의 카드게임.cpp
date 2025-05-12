#include <bits/stdc++.h>

using namespace std;

int p1[9];
bool isUsed[19];
int p2[9];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {
        fill(isUsed, isUsed + 19, false);
        for(int i = 0; i < 9; i++)
        {
            cin >> p1[i];
            isUsed[p1[i]] = true;
        }
        
        int idx = 0;
        for(int i = 1; i <= 18; i++)
        {
            if(!isUsed[i])
            {
                p2[idx++] = i;
            }
        }
        
        int ans1 = 0;
        int ans2 = 0;
        
        int p1Cnt = 0;
        int p2Cnt = 0;
        
        do
        {
			p1Cnt = 0;
          	p2Cnt = 0;
            
			for(int i = 0; i < 9; i++)
            {
                if(p1[i] > p2[i]) p1Cnt += (p1[i] + p2[i]);
                else p2Cnt += (p1[i] + p2[i]);
            }
            
            if(p1Cnt > p2Cnt) ans1++;
            else if(p1Cnt < p2Cnt) ans2++;
            
        } while(next_permutation(p2, p2 + 9));
        
        cout << "#" << t << " " << ans1 << " " << ans2 << "\n";
    }
    return 0;
}