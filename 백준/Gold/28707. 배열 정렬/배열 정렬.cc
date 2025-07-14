#include <bits/stdc++.h>
using namespace std;

int n, m;
string A;
vector<tuple<int, int, int>> edges;
unordered_map<string, int> dist;

void Dijkstra() {
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

    dist[A] = 0;
    pq.push({0, A});

    while (!pq.empty()) {
        auto [curCost, curStr] = pq.top(); pq.pop();

        if (dist[curStr] < curCost) continue;

        for (auto [l, r, c] : edges) {
            string nextStr = curStr;
            swap(nextStr[l], nextStr[r]);

            if (!dist.count(nextStr) || dist[nextStr] > curCost + c) {
                dist[nextStr] = curCost + c;
                pq.push({dist[nextStr], nextStr});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        A += (char)(input[i] + '0'); // 숫자를 문자로 저장 (0~9)
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        edges.push_back({l - 1, r - 1, c});
    }

    Dijkstra();

    // 목표 상태: 정렬된 A
    sort(input.begin(), input.end());
    string goal;
    for (int v : input) goal += (char)(v + '0');

    if (dist.count(goal)) cout << dist[goal] << "\n";
    else cout << "-1\n";

    return 0;
}
