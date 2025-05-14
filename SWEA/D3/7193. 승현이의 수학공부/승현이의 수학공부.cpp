#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n;
        string x;

        cin >> n >> x;

        int sum = 0;
        for(int i = 0; i < (int)x.length(); i++)
        {
            sum += x[i] - '0';
        }

        cout << "#" << t << " " << sum % (n - 1) << "\n";
        
    }
    return 0;
}