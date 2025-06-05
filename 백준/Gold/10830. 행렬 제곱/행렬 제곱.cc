#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll b;

ll A[5][5]; // 입력

ll ans[5][5]; // 정답

ll tmp[5][5]; // SquareMatrix() 결과 임시 저장

// 행렬 제곱

void SquareMatrix(ll x[5][5], ll y[5][5])
{
    memset(tmp, 0, sizeof(tmp));

    // 행렬 제곱 연산
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                tmp[i][j] += (x[i][k] * y[k][j]);
            }

            tmp[i][j] %= 1000;
        }
    }

    // 정답 배열에 값 복사
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            x[i][j] = tmp[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }

        ans[i][i] = 1; // 단위 행렬로 초기화
    }

    while(b > 0)
    {
        // 홀수이면 일단 정답 * A 한 번 진행
        // 짝수에서 시작해도 마지막 한 번은 무조건 1 진행됨
        if(b % 2 == 1) SquareMatrix(ans, A);

        SquareMatrix(A, A);
        b /= 2;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}