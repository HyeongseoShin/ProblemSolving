#include <bits/stdc++.h>

using namespace std;

int n, s;

int arr[21];

int cnt = 0;

// (현재 부분수열의 원소 개수, 현재 부분 수열의 합)
void func(int cur, int sum);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    func(0, 0);

    // 공집합 빼기
    if(s == 0) {
        cnt--;
    }

    cout << cnt << "\n";


    return 0;
}

void func(int cur, int sum) {
    if(cur == n) {
        if(sum == s) {
            cnt++;
        }
        return;
    }

    // 현재 arr[cur]을 선택하지 않았을 때
    func(cur + 1, sum);

    // 현재 arr[cur]을 선택했을 때
    func(cur + 1, sum + arr[cur]);

}