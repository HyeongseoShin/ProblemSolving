#include <bits/stdc++.h>

using namespace std;

int n;

// 꽃 정보 <피는 날짜, 지는 날짜>
vector<pair<int, int>> flowers;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;

        int open = m1 * 100 + d1;
        int close = m2 * 100 + d2;

        flowers.push_back({open, close});
    }

    // 피는 날짜 순으로 오름차순 정렬
    sort(flowers.begin(), flowers.end());

    int cur = 301; // 지금까지 연속으로 커버된 마지막 날짜
    int idx = 0; // 현재 보고 있는 꽃
    int ans = 0; // 심어야하는 꽃 개수 (정답)

    while(cur < 1201)
    {
        int best = cur; // 이번 단계에서 찾은 가장 마지막에 지는 꽃 날짜

        int open = flowers[idx].first;
        int close = flowers[idx].second;

        while(idx < n && open <= cur)
        {
            best = max(best, close);
            idx++;

            open = flowers[idx].first;
            close = flowers[idx].second;
        }

        if(best == cur) // 확장 불가
        {
            ans = 0;
            break;
        }

        cur = best;
        ans++;
    }

    cout << ans << "\n";

    return 0;
}