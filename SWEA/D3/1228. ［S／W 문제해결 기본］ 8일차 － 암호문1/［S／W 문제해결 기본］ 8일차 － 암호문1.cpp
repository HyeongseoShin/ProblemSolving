#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin>> n;
        
        list<int> nums;
        
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            
           nums.push_back(x);
        }
        
        int m;
        cin >> m;
        
        for(int i = 0; i < m; i++)
        {
            char op;
            cin >> op;
            
            int st, cnt;
            cin >> st >> cnt;
            
            list<int> tmp;
            auto it = nums.begin();
			
            for(int j = 0; j < st; j++)
            {
                it++;
            }
            
            for(int j = 0; j < cnt; j++)
            {
				int x;
                cin >> x;
                tmp.push_back(x);
            }
            
            nums.splice(it, tmp);
           
        }
        
        cout << "#" << t << " ";

        int cnt = 0;
        for(auto num : nums)
        {
            if(cnt == 10) break;
            cout << num << " ";
            cnt++;
        }
        cout << "\n";
    }
    return 0;
}