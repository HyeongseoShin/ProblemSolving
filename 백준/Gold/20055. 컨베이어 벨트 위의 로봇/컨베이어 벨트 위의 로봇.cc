#include <bits/stdc++.h>

using namespace std;

int n, k;

int status[250]; // 내구도 현황
bool isRobot[250]; // 로봇이 있는지 없는지

vector<int> robot; // 로봇의 위치 저장

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < 2 * n; i++)
    {
        cin >> status[i];
    }

    int ans = 0;
    int cnt = 1;

    int st = 0;
    int en = n - 1;

    while(true)
    {
        // 1. 벨트 & 로봇 한 칸 회전
        st--;
        if(st < 0) st = 2 * n - 1;

        en--;
        if(en < 0) en = 2 * n - 1;

        // 언제나 로봇이 내리는 위치에 도착하면 내림
        if(isRobot[en])
        {
            isRobot[en] = false;
            
            robot.erase(robot.begin());
        }

        // 2. 가장 앞에 있는 로봇부터 한 칸 이동
        for(int i = 0; i < (int)robot.size(); i++)
        {
            int cur = robot[i];
            int nxt = (cur + 1) % (2 * n);

            // 다음 위치에 로봇이 있으면 Pass
            if(isRobot[nxt]) continue;

            // 내구도가 1보다 작으면 Pass
            if(status[nxt] < 1) continue;

            // 로봇 없으면 이동
            isRobot[cur] = false;
            robot[i] = nxt;
            isRobot[nxt] = true;

            // 내구도 감소
            status[nxt]--;

            // 내구도 0이면 ++
            if(status[nxt] == 0) ans++;

            // 로봇이 내리는 칸에 도착하면 로봇 내리기
            if(nxt == en)
            {
                isRobot[nxt] = false;

                // 로봇 삭제
                robot.erase(robot.begin());
                i--;
            }
        }

        // 3. 올리는 위치 내구도 0 아니면 올리기
        if(status[st] > 0)
        {
            isRobot[st] = true;
            robot.push_back(st);
            status[st]--;

            if(status[st] == 0) ans++;
        }

        if(ans >= k) break;
        cnt++;
    }

    cout << cnt << "\n";



    return 0;
}