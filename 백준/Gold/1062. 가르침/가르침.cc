#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> words;
bool readable[26]; // 알파벳 읽을 수 있는지 여부
int ans = 0;

int GetCnt() {
    int cnt = 0;
    for (auto &s : words) {
        bool isPossible = true;
        for (char c : s) {
            if (!readable[c - 'a']) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) cnt++;
    }
    return cnt;
}

void GetAns(int start, int learned) {
    if (learned == k) {
        ans = max(ans, GetCnt());
        return;
    }

    for (int i = start; i < 26; i++) {
        if (readable[i]) continue;
        readable[i] = true;
        GetAns(i + 1, learned + 1);
        readable[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    if (k < 5) { // a, n, t, i, c 필수
        cout << 0 << "\n";
        return 0;
    }

    // 단어 입력
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // 앞뒤 "anta"와 "tica" 제거
        s = s.substr(4, s.size() - 8);
        words.push_back(s);
    }

    // 필수 알파벳
    readable['a' - 'a'] = true;
    readable['n' - 'a'] = true;
    readable['t' - 'a'] = true;
    readable['i' - 'a'] = true;
    readable['c' - 'a'] = true;

    k -= 5;

    GetAns(0, 0);

    cout << ans << "\n";
    return 0;
}
