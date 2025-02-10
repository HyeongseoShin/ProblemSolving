#include <bits/stdc++.h>
#include <stack>
#include <vector>

using namespace std;

// (값, 인덱스 형태로 저장)
stack<pair<int, int>> S;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    S.push(make_pair(100000001, 0));

    for(int i = 1; i <= n; i++) {
        int num;

        cin >> num;

        while(S.top().first < num) {
            S.pop();
        }

        cout << S.top().second << " ";
        S.push(make_pair(num, i));
    }
    cout << "\n";

}