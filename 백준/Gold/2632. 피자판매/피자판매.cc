#include <bits/stdc++.h>

using namespace std;

int pizza;
int m, n;

int A[1005];
int B[1005];

vector<int> sumA;
vector<int> sumB;

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> pizza;
    cin >> m >> n;

    for(int i = 0; i < m; i++)
    {
        cin >> A[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    // 아무 것도 안 골랐을 때
    sumA.push_back(0);

    // m개 모두 선택하는 경우 중복되므로
    // 1 ~ m-1개 고르는 경우 추가
    for(int i = 0; i < m; i++)
    {
        int sum = 0;
        for(int j = i; j < i + m - 1; j++)
        {
            sum += A[j % m];
            sumA.push_back(sum);
        }
    }

    // n개 모두 고르는 경우 마지막에 따로 추가
    sumA.push_back(accumulate(A, A + m, 0));

    // 아무 것도 안 골랐을 때
    sumB.push_back(0);

    // m개 모두 선택하는 경우 중복되므로
    // 1 ~ m-1개 고르는 경우 추가
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < i + n - 1; j++)
        {
            sum += B[j % n];
            sumB.push_back(sum);
        }
    }

    // n개 모두 고르는 경우 마지막에 따로 추가
    sumB.push_back(accumulate(B, B + n, 0));

    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());

    for(int i = 0; i < (int)sumA.size(); i++)
    {
        if(pizza - sumA[i] < 0) break;
        auto upper = upper_bound(sumB.begin(), sumB.end(), pizza - sumA[i]);
        auto lower = lower_bound(sumB.begin(), sumB.end(), pizza - sumA[i]);
        
        ans += (upper - lower);
    }

    cout << ans << "\n";

    return 0;
}