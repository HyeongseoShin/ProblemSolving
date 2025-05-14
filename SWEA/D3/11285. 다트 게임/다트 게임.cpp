#include <bits/stdc++.h>

using namespace std;

int score[11] = {0, 200, 180, 160, 140, 120, 100, 80, 60, 40, 20};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n;
        cin >> n;

        int ans = 0;
        while(n--)
        {
            int x, y;
            cin >> x >> y;

            for(int i = 10; i >= 1; i--)
            {
                if(x * x + y * y <= score[i] * score[i])
                {
                    ans += i;
                    break;
                }
            }
        }

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}