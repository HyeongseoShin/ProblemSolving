#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 0;

// 행, 열에 퀸 있는지 확인
bool row[11];
bool col[11];

// 왼쪽 대각선, 오른쪽 대각선에 퀸 있는지 확인
bool ld[22];
bool rd[22];

void GetAns(int idx, int cnt)
{
    if(cnt == n)
    {
        ans++;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(col[i]) continue;
        if(ld[idx + i]) continue;
        if(rd[n - (i - idx)]) continue;

        row[idx] = true;
        col[i] = true;
        ld[idx + i] = true;
        rd[n - (i - idx)] = true;

        GetAns(idx + 1, cnt + 1);

        row[idx] = false;
        col[i] = false;
        ld[idx + i] = false;
        rd[n - (i - idx)] = false;
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

        ans = 0;
        GetAns(0, 0);

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}