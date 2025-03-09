#include <bits/stdc++.h>

using namespace std;

int n, k, p, x;

// 각 수마다 켜져 있는 LED 표시
int LED[10][7] = 
{
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> p >> x;

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i == x) continue;

        int cur = i;
        int tmpX = x;

        int cnt = 0;
        for(int j = 0; j < k; j++)
        {
            int curMod = cur % 10;
            int tmpXMod = tmpX % 10;

            for(int k = 0; k < 7; k++)
            {
                if(LED[curMod][k] != LED[tmpXMod][k]) cnt++;                
            }

            cur /= 10;
            tmpX /= 10;
        }

        if(cnt <= p) ans++;
    }

    cout << ans << "\n";


    return 0;
}