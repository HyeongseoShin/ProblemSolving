#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool CheckNotPrime(ll x)
{
    for(int i = 2; i < x; i++)
    {
        if(x % i == 0) return true;
    }
    
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {
        ll n;
        cin >> n;
        
       for(ll i = 4; i <= 1000000000; i++)
       {
           if(CheckNotPrime(i) && CheckNotPrime(i + n))
           {
               cout << "#" << t << " " << i+n << " " << i << "\n";
               break;
           }
       }
        
    }
    return 0;
}