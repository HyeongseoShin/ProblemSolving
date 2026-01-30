#include <bits/stdc++.h>

using namespace std;

int w, h;
char board[25][25];
int dist[25][25]; // BFS용 거리 배열
int adj[11][11]; // 로봇 ~ 더러운 곳, 더러운 곳 ~ 더러운 곳 간의 거리

vector<pair<int, int>> trashPos; // 더러운 곳 위치 좌표
vector<pair<int, int>> targetPos; // 0 : 로봇, 1 ~ : 더러운 곳

int stX, stY;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int targetCnt;

// idx ~ 다른 곳까지의 거리 저장
void bfs(int idx)
{
    memset(dist, -1, sizeof(dist));
    
    queue<pair<int, int>> q;

    auto [x, y] = targetPos[idx];
    q.push({x, y});
    dist[x][y] = 0;

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= h || nY < 0 || nY >= w) continue;
            if(board[nX][nY] == 'x') continue;
            if(dist[nX][nY] != -1) continue;

            dist[nX][nY] = dist[curX][curY] + 1;
            q.push({nX, nY});
        }
    }

    // 지점 간 거리 배열 업데이트
    for(int i = 0; i < targetCnt; i++)
    {
        auto [x, y] = targetPos[i];
        int d = dist[x][y];

        if(d == -1) adj[idx][i] = -1;
        else adj[idx][i] = d;
    }

}


int getAns(int x, int y)
{
    bool isPossible = true;

    // 각 지점 간의 거리 계산
    for(int i = 0; i < targetCnt; i++)
    {
        bfs(i);
        
        // 접근 못하는 더러운 곳 있으면 실패
        for(int j = 0; j < targetCnt; j++)
        {
            if(adj[i][j] == -1)
            {
                return -1;
            }
        }
    }

    // 순열 이용해 방문 순서 결정
    vector<int> p;
    for(int i = 1; i < targetCnt; i++) p.push_back(i);
    
    int minDist = INT_MAX;

    do {
        int curDist = 0;
        int cur = 0;

        for(int nxt : p)
        {
            curDist += adj[cur][nxt];
            cur = nxt;
        }

        minDist = min(minDist, curDist);

    } while(next_permutation(p.begin(), p.end()));

    return minDist;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        cin >> w >> h;

        if(w == 0 && h == 0) break;

        trashPos.clear();
        targetPos.clear();

        for(int i = 0; i < h; i++)
        {
            string s;
            cin >> s;

            for(int j = 0; j < w; j++)
            {
                board[i][j] = s[j];

                if(board[i][j] == 'o')
                {
                    stX = i;
                    stY = j;
                }

                else if(board[i][j] == '*') trashPos.push_back({i, j});
            }
        }

        targetPos.push_back({stX, stY});

        for(int i = 0; i < (int)trashPos.size(); i++)
        {
            auto [x, y] = trashPos[i];
            targetPos.push_back({x, y});
        }

        targetCnt = (int) targetPos.size();

        cout << getAns(stX, stY) << "\n";
    }

    return 0;
}