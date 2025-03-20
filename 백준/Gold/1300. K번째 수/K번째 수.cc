#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    int s = 1;
    int e = k;

    long ans = 0;

    while(s <= e) {
        int mid = (s + e) / 2;
        long minCnt = 0; // 중앙값보다 작은 수의 개수

        for(int i = 1; i <= n; i++) {
            minCnt += min(mid / i, n);
        }

        if(minCnt < k) {
            s = mid + 1;
        }
        else if(minCnt >= k) {
            e = mid - 1;
            ans = mid;
        }
    }

    cout << ans << "\n";

    return 0;
}