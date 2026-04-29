#include <bits/stdc++.h>

using namespace std;

int ans = 0;

int solution(vector<int> players, int m, int k) {
    // <현재 서버 개수, 소멸 시간>
    queue<pair<int, int>> q;
    int curServer = 0;
    
    for(int i = 0; i < (int)players.size(); i++)
    {
        // 소멸 시간 끝나면 서버 소멸됨
        if(!q.empty())
        {
            auto [curCnt, curTime] = q.front();
            if(curTime == i)
            {
                curServer -= curCnt;
                q.pop();
            }
        }
        
        int curPlayers = players[i];
        
        // 현재 서버가 현재 인원 감당 가능하다면 패스
        if(curPlayers / m <= curServer) continue;
        
        // 현재 증설된 서버 없으면 추가
        int val = (curPlayers / m) - curServer;
        curServer += val;
        ans += val;
        q.push({val, i + k});
    }
    return ans;
}