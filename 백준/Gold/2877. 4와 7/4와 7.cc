#include <bits/stdc++.h>

using namespace std;

int n;

int k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i < 100; i++)
    {
        if((pow(2, i) - 1) <= n && n <= (pow(2, i+1) - 2))
        {
            k = i;
            break;
        }
    }

    n = n - (pow(2,k) - 1);

    // cout << n << "\n";

    for(int i = k-1; i >= 0; i--)
    {
        int temp = (n >> i) & 1;
        if(temp == 0) cout << "4";
        else cout << "7";
    }
    cout << "\n";


    return 0;
}