#include <bits/stdc++.h>

using namespace std;

set<int> primeNum;

bool IsPrime(int target)
{
    if(primeNum.find(target) != primeNum.end() || target <= 1) return false;
    
    primeNum.insert(target);
    for(int i = 2; i < target; i++)
    {
        if(target % i == 0) return false;
    }
    
    return true;
}
int solution(string numbers) {
    int ans = 0;
    
    int n = (int)numbers.length();
    vector<char> v (numbers.begin(), numbers.end());
    
    sort(v.begin(), v.end());
    
    int idx = 1;
    while(idx <= n)
    {
        do
        {
            string s = "";
            for(int i = 0; i < idx; i++)
            {
                s += v[i];
            }
            
            if(IsPrime(stoi(s)))
            {
                ans++;
                cout << s << "\n";
            }
        } while(next_permutation(v.begin(), v.end()));    
        
        idx++;
    }
    
    return ans;
    
}