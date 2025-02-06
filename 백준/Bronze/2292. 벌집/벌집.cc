// https://www.acmicpc.net/problem/2292
#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if(n == 1)
    {
        cout << "1\n";
        return 0;
    }
    
    int cnt = 1;
    for(int i = 1; ; i++)
    {
        cnt += (i * 6);

        if(n <= cnt)
        {
            cout << i+1 << "\n";
            break;
        }
    }

    return 0;
}