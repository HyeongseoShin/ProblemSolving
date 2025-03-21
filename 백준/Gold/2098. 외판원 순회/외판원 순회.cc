#include <iostream>
#include <climits>

using namespace std;

int n;
int w[16][16]; // 입력 배열
int dp[16][1 << 16] = {0}; // dp[c][v] : 현재 c도시이고 v방문한 상태에서 남은 도시 방문 최소 cost

#define INF 1000000 * 16 + 1;

int tsp(int c, int v); // tsp 연산 실행

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    int ans = tsp(0, 1); // 0 -> 1번째 도시로 시작

    cout << ans << "\n";

    return 0;
}

int tsp (int c, int v) {
    // 모든 도시 방문했다면
    if(v == (1 << n) - 1) {
        // 출발 도시로 돌아갈 수 없으면 무한대 return
        if(w[c][0] == 0) {
            return INF;
        }
        else {
            return w[c][0];
        }
    }
    
    // 이미 방문한 도시는 다시 계산 필요 X (memoization)
    if(dp[c][v] != 0) {
       return dp[c][v]; 
    }

    int minVal = INF;

    for(int i = 0; i < n; i++) {
        // 방문하지 않은 도시이고 길이 있을 때
        if(w[c][i] != 0 && (v & (1 << i)) == 0) {
            minVal = min(minVal, tsp(i, (v | (1 << i))) + w[c][i]);
        }
    }

    dp[c][v] = minVal;
    return dp[c][v];
}