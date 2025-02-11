// https://www.acmicpc.net/problem/14719
#include <bits/stdc++.h>

using namespace std;

int blocks[501];

int w, h;

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;

    for(int i = 0; i < h; i++)
    {
        int x;

        cin >> x;

        blocks[i] = x;
    }

    for(int i = 0; i < h; i++)
    {
        int l = 0;
        int r = 0;

        // 나보다 왼쪽에서 가장 높은 블럭의 층 수
        for(int j = 0; j < i; j++)
        {
            l = max(l, blocks[j]);
        }

        // 나보다 오른쪽에서 가장 높은 블럭의 층 수
        for(int j = i; j < h; j++)
        {
            r = max(r, blocks[j]);
        }

        // 내가 왼쪽 오른쪽 최댓값보다 작다면 빗물이 고일 수 있음
        if(blocks[i] < l && blocks[i] < r)
        {
            // 둘 중 작은 블록의 층 - 내 층
            ans += min(l, r) - blocks[i];
        }
    }

    cout << ans << "\n";

    return 0;
}