#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

bool isPrime[MAX];

int main()
{
    fill(isPrime, isPrime + MAX, true);

    for(int i = 2; i <= sqrt(MAX); i++)
    {
        if(!isPrime[i]) continue;
        for(int j = i + i; j <= MAX; j += i)
        {
            isPrime[j] = false;
        }
    }

    for(int i = 2; i <= MAX; i++)
    {
        if(isPrime[i]) cout << i << " ";
    }
    cout << "\n";
}