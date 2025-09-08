#include <bits/stdc++.h>

using namespace std;

int board[3][3];

// 문자열로 현재 퍼즐의 상태 저장
string status;

// <문자열, 변경 횟수> : 해당 상태로 되는 데까지 변경한 횟수
unordered_map<string, int> cnt;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void BFS()
{
    queue<string> q;
    q.push(status);
    cnt[status] = 0;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if(cur == "123456780") return;

        // 0의 위치 찾기
        int pos = cur.find('0');

        int curX = pos / 3;
        int curY = pos % 3;

        for(int i = 0; i < 4; i++)
        {   
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= 3 || nY < 0 || nY >= 3) continue;

            string nxt = cur;
            
            int nPos = nX * 3 + nY;

            swap(nxt[pos], nxt[nPos]);

            // 이미 방문했던 상태면 패스
            if(cnt.find(nxt) != cnt.end()) continue;

            q.push(nxt);

            // 해당 퍼즐 상태까지 변경 횟수 업데이트
            cnt[nxt] = cnt[cur] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> board[i][j];
            status += (board[i][j] + '0'); // 퍼즐 상태 문자열로 저장
        }
    }

    BFS();

    // 도달하지 못했으면 실패
    if(cnt.find("123456780") == cnt.end()) cout << -1 << "\n";
    else cout << cnt["123456780"] << "\n";

    return 0;
}