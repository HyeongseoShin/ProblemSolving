#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

string s;

int maxDp[20][20];
int minDp[20][20];

int calc (int a, int b, char op)
{
    switch(op)
    {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '*':
            return (a * b);
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> s;

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            maxDp[i][j] = INT_MIN;
            minDp[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0) maxDp[i][i] = minDp[i][i] = s[i] - '0';
    }

    // += 2씩 하는 이유는 연산 기호는 건너뛰고 숫자만 계산
    // n / 2번 실행
    for(int sz = 3; sz <= n; sz += 2)
    {
        // 시작점
        for(int i = 0; i < n; i += 2)
        {
            // 끝점
            int j = i + sz - 1;
            if(j >= n) continue;

            for(int k = i + 1; k < j; k += 2)
            {
                maxDp[i][j] = max(maxDp[i][j], calc(maxDp[i][k-1], maxDp[k+1][j], s[k]));
                maxDp[i][j] = max(maxDp[i][j], calc(maxDp[i][k-1], minDp[k+1][j], s[k]));
                maxDp[i][j] = max(maxDp[i][j], calc(minDp[i][k-1], maxDp[k+1][j], s[k]));
                maxDp[i][j] = max(maxDp[i][j], calc(minDp[i][k-1], minDp[k+1][j], s[k]));

                minDp[i][j] = min(minDp[i][j], calc(maxDp[i][k-1], maxDp[k+1][j], s[k]));
                minDp[i][j] = min(minDp[i][j], calc(maxDp[i][k-1], minDp[k+1][j], s[k]));
                minDp[i][j] = min(minDp[i][j], calc(minDp[i][k-1], maxDp[k+1][j], s[k]));
                minDp[i][j] = min(minDp[i][j], calc(minDp[i][k-1], minDp[k+1][j], s[k]));
            }
        }
    }

    cout << maxDp[0][n-1] << "\n";


    return 0;
}