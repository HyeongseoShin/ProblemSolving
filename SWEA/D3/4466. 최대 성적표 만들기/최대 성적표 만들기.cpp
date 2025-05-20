#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v;

        for(int i = 0; i < n; i++)
        {
            int score;
            cin >> score;
            v.push_back(score);
        }

        sort(v.begin(), v.end(), greater<>());

        int ans = 0;
        for(int i = 0; i < k; i++)
        {
            ans += v[i];
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}