#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans[10];

// n이 구성되어 있는 수를 찾고
// 그 수의 등장 횟수 ++
void calc(long long n, long long ten)
{
    while(n > 0)
    {
        ans[n % 10] += ten;
        n /= 10;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll st = 1;
    ll en;
    ll ten = 1; // 현재 자릿수

    cin >> en;

    while(st <= en)
    {
        // 시작점의 일의 자리를 0으로 맞출 때까지 ++
        // 일의 자리 맞추기 전까지는 구성 되어 있는 수의 등장 횟수 일일이 calc()
        while(st % 10 != 0 && st <= en)
        {
            calc(st, ten);
            st++;
        }

        if(st > en) break;

        // 끝 점의 일의 자리를 9로 맞출 때까지 --
        // 일의 자리 맞추기 전까지는 구성 되어 있는 수의 등장 횟수 일일이 calc()
        while(en % 10 != 9 && st <= en)
        {
            calc(en, ten);
            en--;
        }

        // 0 ~ 9의 등장 횟수가 모두 동일한게 반복되도록 세팅 완료
        ll cnt = (en / 10 - st / 10 + 1);

        for(int i = 0; i < 10; i++)
        {
            ans[i] += (cnt * ten);
        }

        st /= 10;
        en /= 10;
        ten *= 10LL;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}