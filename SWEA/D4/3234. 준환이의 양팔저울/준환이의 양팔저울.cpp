#include <bits/stdc++.h>

using namespace std;

int choo[9];

int sum = 0;

bool isUsed[9];

int n;

int ans = 0;

int fact(int x)
{
    if(x == 1) return 1;
    return x * fact(x-1);
}
void GetAns(int l, int r, int cnt)
{
    // 모든 추를 다 썼을 때
    if(cnt == n)
    {
        ans++;
        return;
    }

    // 남아 있는 추를 모두 오른쪽에 놓아도 성립할 때 (r + (sum - l - r)) => sum - l
    if(l >= sum - l)
    {
        ans += pow(2, n - cnt) * fact(n - cnt);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(isUsed[i]) continue;

        isUsed[i] = true;

        // 오른쪽에 추 놓을 수 있을 때
        if(l >= r + choo[i]) GetAns(l, r + choo[i], cnt + 1);

        // 왼쪽은 무조건 놓을 수 있음
        GetAns(l + choo[i], r, cnt + 1);

        isUsed[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> n;

        sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> choo[i];
            sum += choo[i];
        }

        ans = 0;
        GetAns(0, 0, 0);

        cout << "#" << t << " " << ans << "\n";

    }
    return 0;
}