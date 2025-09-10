#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1,-1};

// <질량, 속도, 방향>
queue<tuple<int, int, int>> board[51][51];

struct Fire {
    int r, c, m, s, d;
};

// 파이어볼 이동
void move()
{
    queue<Fire> fires;
    
    // 파이어볼 이동
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int sz = (int)board[i][j].size();

            while(sz--)
            {
                auto [m, s, d] = board[i][j].front();
                board[i][j].pop();

                // 방향 d로 속력s칸 만큼 이동
                // 행, 열은 끝과 끝이 연결되어 있음

                int nX = (i + (dx[d] * s)) % n;
                int nY = (j + (dy[d] * s)) % n;

                if(nX < 0) nX += n;
                if(nY < 0) nY += n;

                // 이동 추가
                fires.push({nX, nY, m, s, d});
            }
        }
    }

    // 실제 이동
    while(!fires.empty())
    {
        auto [r, c, m, s, d] = fires.front();
        fires.pop();

        board[r][c].push({m, s, d});
    }

    // 한 칸에 파이어볼 2개 이상 있으면 합치기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int sz = (int)board[i][j].size();

            if(sz < 2) continue;

            int totalM = 0;
            int totalS = 0;
            bool isDirSame = true;
            int curMod = -1;

            while(!board[i][j].empty())
            {
                auto [m, s, d] = board[i][j].front();
                board[i][j].pop();

                // 전체 질량 합
                totalM += m;

                // 전체 속력 합
                totalS += s;

                // 방향이 모두 홀수인지 짝수인지 확인
                if(curMod == -1) curMod = d % 2;
                else if(curMod != d % 2) isDirSame = false;
            }

            // 합친 질량 / 5
            totalM /= 5;

            // 합친 속력 / 합친 개수
            totalS /= sz;

            // 질량이 0이면 없어지도록
            if(totalM == 0) continue;

            // 방향이 모두 홀 or 짝이면 0, 2, 4, 6
            int newDir[4]= {0, 2, 4, 6};
            
            // 하나라도 다르면 1, 3, 5, 7
            if(!isDirSame)
            {
                newDir[0]++;
                newDir[1]++;
                newDir[2]++;
                newDir[3]++;
            }

            // 합쳐진 파이어볼은 4개로 분할
            for(int dir = 0; dir < 4; dir++)
            {
                board[i][j].push({totalM, totalS, newDir[dir]});
            }
        }
    }
}

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++)
    {
        int r, c, m, s, d;

        cin >> r >> c >> m >> s >> d;

        // 0-indexed로 변경
        board[r-1][c-1].push({m, s, d});
    }

    while(k--)
    {
        move();
    }

    // 남아있는 파이어볼의 질량 구하기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            
            while(!board[i][j].empty())
            {
                auto [m, s, d] = board[i][j].front();
                board[i][j].pop();
                ans += m;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}