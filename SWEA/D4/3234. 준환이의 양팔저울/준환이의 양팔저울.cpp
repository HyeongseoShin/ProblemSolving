#include <bits/stdc++.h>

using namespace std;

int weights[9];
int sum = 0;
int n;
int ans = 0;

bool isUsed[9];

// int expo[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
// int fact[10] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int fact(int x)
{
    if(x == 1) return 1;
    return x * fact(x - 1);
}

void GetAns(int cnt, int left, int right)
{
    if(cnt == n)
    {
        ans++;
        return;
    }

    // 시간 초과 제거
    // 남은 추를 어떻게 올려도 상관 없으면 (남은 추가 현재 left보다 작으면)
    // 한 번에 구하기
    if(sum - left <= left)
    {
        // ans += (expo[n - cnt] * fact[n - cnt]);
        ans += pow(2, n - cnt) * fact(n - cnt);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(isUsed[i]) continue;

        isUsed[i] = true;
        GetAns(cnt + 1, left + weights[i], right);
        if(left >= right + weights[i]) GetAns(cnt + 1, left, right + weights[i]);
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
            cin >> weights[i];
            sum += weights[i];
        }

        ans = 0;
        fill(isUsed, isUsed + n, false);
        GetAns(0, 0, 0);

        cout << "#" << t << " " << ans << "\n";
        
    }
    return 0;
}