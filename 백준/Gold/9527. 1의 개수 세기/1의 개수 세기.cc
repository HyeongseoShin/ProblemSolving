
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, b;
ll d[55];

// 최상위 비트부터 진행하며 위치별 1의 개수 구한 후 정답에 더함
ll GetAns(ll x)
{
    // 만약 현재 비트가 1이면 (i 이하 하위 비트의 1의 개수 누적 합) + (현재 비트의 1의 개수)
    // 현재 비트의 1의 개수 = x - (2^i) + 1 = 현재 비트를 제외한 하위 비트로 표현한 수 + 1
    // + 1 ==> 최상위 비트 1이가 나머지 비트 다 0인 수

    // 최하위 비트 1인지 0인지 확인
    ll ans = x & 1;

    // 현재수의 자릿수 구하는 것보다 최상위 비트 (54)번째부터 그냥 검사 시작
    for(int i = 54; i > 0; i--)
    {
        if(x & (1LL << i)) // 현재 비트가 1이라면
        {
            ans += d[i-1] + (x - (1LL << i) + 1);
            x -= (1LL << i);
        }
    }

    return ans;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    // 최상위 비트가 i이하인 수의 1의 개수를 누적합으로 계산
    // 가장 오른쪽 => 0부터 시작
    d[0] = 1;
    for(ll i = 1; i < 55; i++)
    {
        d[i] = d[i-1] * 2 + (1LL << i);
    }

    cout << GetAns(b) - GetAns(a - 1) << "\n";

    return 0;
}