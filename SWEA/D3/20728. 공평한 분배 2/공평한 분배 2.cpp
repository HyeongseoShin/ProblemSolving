#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    for(int test = 1; test <= t; test++)
    {
        int n, k;
        cin >> n >> k;
        
        vector<int> candy;
        
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            candy.push_back(x);
        }
        
        int st = 0;
        int en = k;
        int minDiff = INT_MAX;
        
        sort(candy.begin(), candy.end());
		while(en <= n)
        {
            int maxVal = *max_element(candy.begin() + st, candy.begin() + en);
            int minVal = *min_element(candy.begin() + st, candy.begin() + en);
            
            minDiff = min(minDiff, maxVal - minVal);
            st++;
            en++;
        }
    
        /*
        while(st <= en)
        {
            while(en < n && en - st < k)
            {
                if(candy[maxIdx] < candy[en]) maxIdx = en;
                if(candy[minIdx] > candy[en]) minIdx = en;
                
                cout << "maxIdx : " << maxIdx << " minIdx : " << minIdx << " candy[maxIdx] : " << candy[maxIdx] << " candy[minIdx] : " << candy[minIdx] << "\n";
                minDiff = min(minDiff, candy[maxIdx] - candy[minIdx]);
                en++;
            }
            
            
            st++;
            //if(maxIdx < st) maxIdx = st;
            //if(minIdx < st) minIdx = st;
            //minDiff = min(minDiff, candy[maxIdx] - candy[minIdx]);
        }
        */
        
        cout << "#" << test << " " << minDiff << "\n";
    }
    return 0;
}