#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test;
    cin >> test;
    
    for(int t = 1; t <= test; t++)
    {
        int n, m;
        cin >> n >> m;
        
        vector<string> A;
        vector<string> B;
        
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            A.push_back(s);
        }
        
        for(int i = 0; i < m; i++)
        {
            string s;
            cin >> s;
            B.push_back(s);
        }
        
        int cnt = n * m;
        
        int stA = 0;
        int stB = 0;
        
        vector<string> result;
        while(cnt--)
        {
            result.push_back(A[stA]+B[stB]);
            stA = (stA + 1) % n;
            stB = (stB + 1) % m;
        }
        
        int q;
        cin >> q;

        cout << "#" << t << " ";
        while(q--)
        {
            int year;
            cin >> year;
            
            int idx = (year - 1) % (n * m);
			cout << result[idx] << " ";
        }
        cout << "\n";
    }
    return 0;
    
}