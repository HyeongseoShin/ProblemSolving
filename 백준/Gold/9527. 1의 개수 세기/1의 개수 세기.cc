#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b;

// 최상위 비트가 i번 이하인 모든 수의 1의 개수합
// 1000이면 i = 3
ll d[55];

// 최상위 비트부터 진행하며 위치별 1의 개수 구한 후 정답에 더함
ll GetOneCnt(ll x)
{
    // 최하위 비트 0 or 1인지 확인
    ll ans = x & 1;

    for(int i = 54; i > 0; i--)
    {
        // 현재 자리 수가 1이면 그 전까지 1의 합 구하기
        // 예) 1100
        // 0000 ~ 0111 까지 1의 개수 ==> d[i-1]
        // 1000 ~ 1100 까지 가장 최상위의 1의 개수
        // => 1000 ~ 1100까지 사이 5개의 수가 있으니까 최상위 비트는 1이 5번 더해져야함
        
        // 현재 비트 1이면
        if(x & (1LL << i))
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

    d[0] = 1;

    for(ll i = 1; i < 55; i++)
    {
        // (1LL << i) == pow(2, i - 1);
        d[i] = d[i-1] * 2 + (1LL << i);
    }

    cout << GetOneCnt(b) - GetOneCnt(a - 1) << "\n";

    return 0;
}