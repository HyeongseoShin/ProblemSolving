#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int solution(int number, int limit, int power) {
    for(int i = 1; i <= number; i++)
    {
        unordered_set<int> us;
        for(int j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                if(us.count(j) > 0) break;
                
                us.insert(j);
                us.insert(i / j);
            }
        }
        
        if((int)us.size() > limit) ans += power;
        else ans += (int)us.size();
    }
    
    return ans;
}