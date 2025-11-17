#include <bits/stdc++.h>

using namespace std;

int n;
int l, p; // 마을까지의 거리, 현재 연료 양

vector<pair<int, int>> station; // {거리, 연료}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        station.push_back({a, b});
    }

    cin >> l >> p;

    station.push_back({l, 0}); // 도착점 삽입
    sort(station.begin(), station.end());

    // 지금 갈 수 있는 주유소 중에서 "연료 제일 큰 곳"을 고르기 위함
    priority_queue<int> pq;

    int cnt = 0; // 주유 횟수
    int curFuel = p; // 현재 연료 (현재 연료로 도달 가능한 최대 거리)
    int idx = 0; // 주유소 인덱스

    while(curFuel < l)
    {
        while(idx < (int)station.size() && station[idx].first <= curFuel) {
            pq.push(station[idx].second);
            idx++;
        }

        // 갈 수 있는 주유소 없으면 마을 도착 불가능
        if(pq.empty())
        {
            cnt = -1;
            break;
        }

        // 연료 가장 많이 주는 주유소에서 주유
        // 연료를 직접 소모 X
        curFuel += pq.top();
        pq.pop();
        cnt++;
    }

    cout << cnt << "\n";

    return 0;
}