#include <bits/stdc++.h>

using namespace std;

int n;

// <점수, 남은 날짜> 점수 기준으로 내림차순 정렬
priority_queue<pair<int, int>> pq;

// 각 날짜 별 과제를 했을 때 얻을 수 있는 최대점
int score[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int d, w;
        cin >> d >> w;

        pq.push({w, d});
    }


    while(!pq.empty())
    {
        auto [w, d] = pq.top();
        pq.pop();

        // 점수 많이 주는 과제는 최대한 미뤘다가 진행해야 함
        for(int i = d; i >= 1; i--)
        {
            // 이 날에 할 과제를 아직 못 정했으면 현재 과제 수행
            if(score[i] == 0)
            {
                score[i] = w;
                break;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= 1000; i++)
    {
        ans += score[i];
    }

    cout << ans << "\n";

    
    return 0;
}