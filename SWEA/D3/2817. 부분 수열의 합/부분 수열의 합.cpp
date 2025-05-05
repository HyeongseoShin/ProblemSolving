#include <bits/stdc++.h>

using namespace std;

int n, k;
int ans;

vector<int> v;

void DFS(int idx, int cur)
{
    if(cur == k)
    {
        ans++;
        return;
    }
    
    for(int i = idx + 1; i < n; i++)
    {
        if(cur + v[i] <= k) DFS(i, cur + v[i]);
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
        cin >> n >> k;
     
        v.resize(n);
        fill(v.begin(), v.end(), 0);
        
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        
        ans = 0;
        
        for(int i = 0; i < n; i++)
        {
	        DFS(i, v[i]);            
        }

        
		        
        cout << "#" << t << " " << ans << "\n";
        
    }
    return 0;
}