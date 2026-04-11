#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll ans = 0;

priority_queue<ll, vector<ll>, greater<>> negative; // 음수
priority_queue<ll> positive; // 양수
int zCnt = 0; // 0 개수
int oneCnt = 0; // 1의 개수 (1 * 1 < 1 + 1)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        if(x < 0LL) negative.push(x);
        else if(x == 1LL) oneCnt++;
        else if(x > 0LL) positive.push(x);
        else zCnt++;
    }

    while((int)negative.size() >= 2)
    {
        ll x1 = negative.top();
        negative.pop();

        ll x2 = negative.top();
        negative.pop();

        ans += (x1 * x2);
    }

    // 남은 수는 0 곱할 수 있으면 곱하기
    while(!negative.empty())
    {
        ll cur = negative.top();
        negative.pop();

        if(zCnt > 0) zCnt--;
        else ans += cur;
    }

    while((int)positive.size() >= 2)
    {
        ll x1 = positive.top();
        positive.pop();

        ll x2 = positive.top();
        positive.pop();

        ans += (x1 * x2);
    }

    while(!positive.empty())
    {
        ll cur = positive.top();
        positive.pop();

        ans += cur;
    }

    ans += oneCnt;

    cout << ans << "\n";

    return 0;
}