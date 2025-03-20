#include <bits/stdc++.h>

using namespace std;

int m, n;

bool isPrime[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    isPrime[1] = true;
    for(int i = 2; i * i <= 1000000; i++)
    {
        if(isPrime[i]) continue;
        for(int j = i * i; j <= 1000000; j += i)
        {
            isPrime[j] = true;
        }
    }

    for(int i = m; i <= n; i++)
    {
        if(!isPrime[i]) cout << i << "\n";
    }

    return 0;
}