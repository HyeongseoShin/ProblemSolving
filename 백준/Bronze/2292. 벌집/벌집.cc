// https://www.acmicpc.net/problem/2292
#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    int cnt = 0;
    int st = 1;
    int en = 1;

    while(true)
    {
        if(st <= n && n <= en)
        {
            cout << cnt + 1 << "\n";
            break;
        }
        cnt++;
        st = en + 1;
        en = st + 6 * cnt - 1;
    }

    return 0;
}