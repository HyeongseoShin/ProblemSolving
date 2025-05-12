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
        
        vector<int> nums;
        
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
            
            vector<int> tmp;
            for(int j = 0; j < cnt; j++)
            {
				int x;
                cin >> x;
                tmp.push_back(x);
            }
			nums.insert(nums.begin() + st, tmp.begin(), tmp.end());
        }            
        
        cout << "#" << t << " ";
        for(int i = 0; i < 10; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}