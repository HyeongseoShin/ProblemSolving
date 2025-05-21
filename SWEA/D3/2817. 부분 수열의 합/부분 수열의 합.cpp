#include <bits/stdc++.h>

using namespace std;

int n, k;
int board[20];
bool isUsed[20];
int ans = 0;

void GetAns(int idx, int cur)
{
    if(cur == k)
    {
        ans++;
        return;
    }

    for(int i = idx; i < n; i++)
    {
        if(isUsed[i]) continue;
        
        isUsed[i] = true;
        GetAns(i + 1, cur + board[i]);
        isUsed[i] = false;
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
        cin >> n >> k;

        for(int i = 0; i < n; i++)
        {
            cin >> board[i];
        }

        ans = 0;
        fill(isUsed, isUsed + 20, false);
        GetAns(0, 0);

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}