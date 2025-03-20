#include <bits/stdc++.h>

using namespace std;

int m, n;

bool isPrime[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    fill(isPrime, isPrime + 1000001, true);

    isPrime[1] = false;

    for(int i = 2; i * i <= n; i++)
    {
        if(!isPrime[i])
        {
            continue;
        }

        for(int j = i * i; j <= n; j += i)
        {
            isPrime[j] = false;
        }
    }

    for(int i = m; i <= n; i++)
    {
        if(isPrime[i])
        {
            cout << i << "\n";
        }
    }



    return 0;
}