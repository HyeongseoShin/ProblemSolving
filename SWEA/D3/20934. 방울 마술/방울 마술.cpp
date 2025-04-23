#include <bits/stdc++.h>

using namespace std;

int ans[3];

int k;

void GetAns(int pos, int cnt)
{
    if(cnt == k)
    {
        ans[pos]++;
        return;
    }
    
    if(pos == 0 || pos == 2) GetAns(1, cnt+1);
	else GetAns(0, cnt+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    
    cin >> t;
    
    for(int test = 1; test <= t; test++)
    {
        string s;
        
        cin >> s >> k;
        
        int st = 0;
        for(int i = 0; i < 3; i++)
        {
            if(s[i] == 'o') st = i;
        }
        
        if(k == 0)
        {
            cout << "#" << test << " " << st << "\n";
            continue;
        }
        
        ans[0] = 0;
        ans[1] = 0;
        ans[2] = 0;
        
        GetAns(st, 0);
        
        int maxIdx = 0;
		for(int i = 1; i < 3; i++)
        {
            if(ans[maxIdx] < ans[i])
            {
                maxIdx = i;
            }
        }
        
        cout << "#" << test << " " << maxIdx << "\n";
        
        
    }
    return 0;
    
}