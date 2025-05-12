#include <iostream>

using namespace std;

int n, m;
int ans = 1;

void GetAns(int cur, int cnt)
{
    if(cnt == 1)
    {
        ans = cur;
        return;
    }
    
    GetAns(cur * n, cnt - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int t = 1; t <= 10; t++)
    {
        int tc;
        cin >> tc;
        
        cin >> n >> m;
        
        ans = 1;
        GetAns(n, m);
        
        cout << "#" << tc << " " << ans << "\n";
    }
    
    return 0;
}