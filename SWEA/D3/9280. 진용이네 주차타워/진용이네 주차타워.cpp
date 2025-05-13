#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n, m;
        cin >> n >> m;

        // 주차 구역 가격
        int price[105];
        for(int i = 1; i <= n; i++)
        {
            cin >> price[i];
        }

        // 차의 무게
        int cars[2005];
        for(int i = 1; i <= m; i++)
        {
            cin >> cars[i];
        }

        // 해당 주차 구역에 차가 있는가?
        bool isUsed[105];
        fill(isUsed, isUsed + 105, false);

        // 해당 차의 주차 구역
        int pos[2005];
        fill(pos, pos + 2005, 0);

        int cnt = m * 2;

        // 대기 큐
        queue<int> q;

        // 총합
        int sum = 0;

        while(cnt--)
        {
            int x;
            cin >> x;

            // 차 들어옴
            if(x > 0)
            {
                int idx = -1;
                for(int i = 1; i <= n; i++)
                {
                    if(!isUsed[i])
                    {
                        idx = i;
                        break;
                    }
                }

                // 자리 있으면 주차
                if(idx != -1)
                {
                    isUsed[idx] = true;
                    pos[x] = idx;
                    sum += (price[idx] * cars[x]);
                }

                else q.push(x);
            }
            // 차 나감
            else 
            {
                int idx = x * -1;
                int curPlace = pos[idx];

                isUsed[curPlace] = false;
                pos[idx] = 0;

                // 대기 중인 차 우선 진입
                if(!q.empty())
                {
                    int waiting = q.front();
                    q.pop();

                    // 주차
                    pos[waiting] = curPlace;
                    isUsed[curPlace] = true;
                    sum += (price[curPlace] * cars[waiting]);
                }
            }

        }

        cout << "#" << t << " " << sum << "\n";
    }

    return 0;
}