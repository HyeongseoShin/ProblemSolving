#include <bits/stdc++.h>

using namespace std;

int n, k;

vector<int> A; // 컨베이어 벨트
vector<int> robotPos; // 로봇 위치
vector<bool> isRobot; // 로봇이 있는지 없는지

int ans = 1;
int zeroCnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    
    for(int i = 0; i < n * 2; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
        isRobot.push_back(false);
    }

    int st = 0; // 현재 올리는 위치
    int en = n - 1; // 현재 내리는 위치
    int zCnt = 0; // 내구도 0인 칸 개수
    int ans = 1; // 현재 단계

    while(true)
    {
        // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        st--;
        en--;
        if(st < 0) st = n * 2 - 1;
        if(en < 0) en = n * 2 - 1;

        // * 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
        if(isRobot[en])
        {
            isRobot[en] = false;
            robotPos.erase(robotPos.begin());
        }

        // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        for(int i = 0; i < (int)robotPos.size(); i++)
        {
            int curPos = robotPos[i];
            int nPos = (curPos + 1) % (n * 2);
            
            // 2-1. 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
            if(isRobot[nPos] || A[nPos] <= 0) continue;
            
            isRobot[curPos] = false;

            isRobot[nPos] = true;
            robotPos[i] = nPos;
            A[nPos]--;

            
            if(A[nPos] == 0) zCnt++;

            // * 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
            if(nPos == en)
            {
                isRobot[nPos] = false;
                robotPos.erase(robotPos.begin() + i);
                i--;
            }
        }

        // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if(A[st] > 0)
        {
            isRobot[st] = true;
            robotPos.push_back(st);
            A[st]--;

            if(A[st] == 0) zCnt++;
        }

        // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
        if(zCnt >= k) break;

        ans++; // 단계 증가
    }

    cout << ans << "\n";

    return 0;
}