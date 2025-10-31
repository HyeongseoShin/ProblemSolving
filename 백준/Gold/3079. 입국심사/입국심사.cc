#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MAX 1000001

int n, m;

ll t[MAX];

ll ans = 0;

ll minTime = LLONG_MAX;

// target초만에 모든 사람들이 심사받을 수 있는지?
bool isPossible(ll target)
{   
    ll cnt = 0;

    // target초 동안 검사할 수 있는 최대 인원 구하기
    for(int i = 0; i < n; i++)
    {
        cnt += (target / t[i]);
    }

    return (cnt >= m);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
        minTime = min(minTime, t[i]);
    }
    
    // 매개 변수 탐색
    // 변수 : 모든 사람들이 심사를 모두 마치게 되는 시간
    ll st = 1;
    ll en = minTime * m;

    while(st <= en)
    {
        ll mid = (st + en) / 2;

        if(isPossible(mid))
        {
            ans = mid;
            en = mid - 1;
        }
        else st = mid + 1;
    }

    cout << ans << "\n";

    return 0;
}