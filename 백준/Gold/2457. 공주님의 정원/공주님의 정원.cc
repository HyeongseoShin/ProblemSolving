#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> flowers;
    for (int i = 0; i < n; ++i) {
        int m1,d1,m2,d2;
        cin >> m1 >> d1 >> m2 >> d2;
        int st = m1 * 100 + d1;
        int en = m2 * 100 + d2;
        flowers.push_back({st, en});
    }

    // start 오름차순, 같으면 end 내림차순 (같은 start일 때 더 긴 구간을 먼저 고려)
    sort(flowers.begin(), flowers.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    int current = 301;    // 지금까지 커버된 마지막 날짜 (우린 [301, 1201) 을 덮어야 함)
    int target = 1201;    // 목표: current >= 1201
    int idx = 0;          // flowers 인덱스
    int ans = 0;
    int nFlowers = flowers.size();

    while (current < target) {
        int best = current; // 이번 단계에서 확장 가능한 최대 끝
        // start <= current 인 모든 꽃을 보면서 best 갱신
        while (idx < nFlowers && flowers[idx].first <= current) {
            best = max(best, flowers[idx].second);
            idx++;
        }
        if (best == current) { // 확장 불가 -> 불가능
            cout << 0 << "\n";
            return 0;
        }
        // 확장 성공
        current = best;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}
