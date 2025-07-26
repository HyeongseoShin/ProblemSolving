#include <bits/stdc++.h>

using namespace std;

vector<int> v;
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    cout << v[0] << " " << v[n-1] << "\n";
    

    
    return 0;
}