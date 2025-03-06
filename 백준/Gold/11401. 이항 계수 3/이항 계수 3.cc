#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll n, k;


// 팩토리얼 구하기
ll fact(ll st, ll en)
{
    ll ret = 1;
    for(ll i = st; i <= en; i++)
    {
        ret = ret * i % MOD;
    }

    return ret;
}

// 거듭 제곱 구하기 Divide & Conquer
// a^m = a^(m/2) * a^(m/2)
ll power(int a, int b)
{
    if(b == 1) return a % MOD;
    ll half = power(a, b / 2);

    if(b % 2 == 1)
    {
        return half * half % MOD * a % MOD;
    }
    else
    {
        return half * half % MOD;
    }
}

int main()
{
    cin >> n >> k;
    
    ll ans = fact(n-k+1, n) * power(fact(1, k), MOD - 2) % MOD;

    cout << ans << "\n";



    return 0;
}