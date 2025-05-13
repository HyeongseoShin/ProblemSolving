#include <bits/stdc++.h>

using namespace std;

int ans;

int people[21];

int n, h;

bool isUsed[21];

void GetAns(int idx, int cur)
{
    if(idx == n)
    {
        if(cur >= h) ans = min(ans, cur);
        return;
    }

    GetAns(idx + 1, cur + people[idx]);
    GetAns(idx + 1, cur);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> n >> h;

        for(int i = 0; i < n; i++)
        {
            cin >> people[i];
        }

        ans = INT_MAX;
        GetAns(0, 0);

        cout << "#" << t << " " << ans - h << "\n";
    }

    


    return 0;
}