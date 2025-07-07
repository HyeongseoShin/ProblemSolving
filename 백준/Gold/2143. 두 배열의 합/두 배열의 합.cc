#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int A[1001];
int B[1001];

vector<int> sumA, sumB;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> B[i];
    }

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += A[j];
            sumA.push_back(sum);
        }
    }

    for(int i = 0; i < m; i++)
    {
        int sum = 0;
        for(int j = i; j < m; j++)
        {
            sum += B[j];
            sumB.push_back(sum);
        }
    }

    long long ans = 0;

    sort(sumB.begin(), sumB.end());

    for(int i = 0; i < (int)sumA.size(); i++)
    {
        int target = t - sumA[i];

        int upper = upper_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
        int lower = lower_bound(sumB.begin(), sumB.end(), target) - sumB.begin();

        ans += (upper - lower);
    }

    cout << ans << "\n";


    return 0;
}