#include <bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

int n;

// <신맛, 쓴맛>
pair<int, int> foods[11];

bool isUsed[11];

// 신맛은 곱, 쓴맛은 합
void GetAns(int curSour, int curBitter, int idx)
{
    if(idx == n)
    {
        // 하나라도 섞은 것만 취급
        if(curBitter > 0) ans = min(ans, abs(curSour - curBitter));
        
        return;
    }

    auto [s, b] = foods[idx];

    // 섞기
    GetAns(curSour * s, curBitter + b, idx + 1);

    // 안 섞기
    GetAns(curSour, curBitter, idx + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        foods[i] = {a, b};
    }

    GetAns(1, 0, 0);

    cout << ans << "\n";

    return 0;
}