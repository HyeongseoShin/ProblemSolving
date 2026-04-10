#include <bits/stdc++.h>

using namespace std;

vector<int> A;

int n, m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        A.push_back(x);
    }

    sort(A.begin(), A.end());

    int l = 0;
    int r = 0;

    int ans = INT_MAX;

    while(r < n)
    {
        int result = A[r] - A[l];

        if(result < m) r++;
        else
        {
            ans = min(ans, result);
            l++;
        }

        if(l > r) r = l;
    }

    cout << ans << "\n";

    return 0;
}