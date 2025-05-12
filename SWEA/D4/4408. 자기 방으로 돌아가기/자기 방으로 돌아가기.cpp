#include <bits/stdc++.h>

using namespace std;

int st[201];
int en[201];
int cnt[201];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n;
        cin >> n;
        
        fill(cnt, cnt + 201, 0);

        for(int i = 0; i < n; i++)
        {
            int from, to;
            cin >> from >> to;
            
            int minVal = min(from, to);
            int maxVal = max(from, to);

            // 홀수 / 짝수 나눠서 방 번호 지정
            // 1번, 2번 --> 1번방
            // 3번, 4번 --> 2번방 ...

            st[i] = minVal / 2 + minVal % 2;
            en[i] = maxVal / 2 + maxVal % 2;
        }

        for(int i = 0; i < n; i++)
        {
            int curFrom = st[i];
            int curTo = en[i];
            
            // 현재 경로 가는 인원 ++
            for(int j = curFrom; j <= curTo; j++)
            {
                cnt[j]++;
            }
        }

        // 모든 인원 복귀 시간 = 가장 많이 겹치는 시간대 이동 인원
        int ans = *max_element(cnt, cnt + 201);

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}