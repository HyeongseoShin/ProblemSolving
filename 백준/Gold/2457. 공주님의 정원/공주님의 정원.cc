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

    // 현재 핀 꽃 중 가장 빨리 지는 꽃
    int minEn = 301;
    
    // 현재 핀 꽃 중 가장 늦게 지는 꽃
    int maxEn = 301;

    int cnt = 1; // 피어있는 꽃의 개수

    for(auto [st, en] : flowers)
    {
        // 이미 모든 꽃 커버 완료
        if(maxEn >= 1201) break;

        if(st > minEn)
        {
            minEn = maxEn;
            cnt++;
        }

        if(st > minEn) break;

        maxEn = max(maxEn, en);
    }


    // 12월 1일 전에 꽃이 지면 실패
    if(maxEn < 1201) cnt = 0;
    cout << cnt << "\n";

    return 0;
}