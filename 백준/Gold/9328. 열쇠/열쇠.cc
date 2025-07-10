#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char board[101][101];

int testCase;

int h, w;

bool hasKey[26]; // 갖고 있는 열쇠

int BFS()
{
    int ans = 0;
    bool vis[101][101];
    memset(vis, false, sizeof(vis));

    queue<pair<int, int>> q;
    queue<pair<int, int>> door[26]; // 열쇠가 없어서 못 들어간 문 위치 저장

    // 입구 찾기
    for(int i = 0; i < h; i++)
    {
        if(board[i][0] != '*' && !vis[i][0])
        {
            q.push({i, 0});
            vis[i][0] = true;
        }
        
        if(board[i][w-1] != '*' && !vis[i][w-1])
        {
            q.push({i, w - 1});
            vis[i][w-1] = true;
        }
        
    }

    for(int j = 0; j < w; j++)
    {
        if(board[0][j] != '*' && !vis[0][j])
        {
            q.push({0, j});
            vis[0][j] = true;
        }
        

        if(board[h-1][j] != '*' && !vis[h-1][j])
        {
            q.push({h - 1, j});
            vis[h-1][j] = true;
        }
        
    }

    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        char c = board[curX][curY];

        // 문서면 ++
        if(c == '$') ans++;

        // 열쇠라면
        else if(c >= 'a' && c <= 'z')
        {
            int k = c - 'a';

            if(!hasKey[k])
            {
                hasKey[k] = true;

                // 열쇠 얻고 열쇠가 없어서 들어가지 못한 문 큐에 삽입
                while(!door[k].empty())
                {
                    auto [nX, nY] = door[k].front();
                    door[k].pop();

                    q.push({nX, nY});
                }
            }
        }

        // 문이라면
        else if(c >= 'A' && c <= 'Z')
        {
            int k = c - 'A';

            // 열쇠 없으면
            // door에 저장 후 continue
            if(!hasKey[k])
            {
                door[k].push({curX, curY});
                continue;
            }
        }

        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if(nX < 0 || nX >= h || nY < 0 || nY >= w) continue;
            if(vis[nX][nY]) continue;
            if(board[nX][nY] == '*') continue;

            vis[nX][nY] = true;
            q.push({nX, nY});
            
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> testCase;

    while(testCase--)
    {
        cin >> h >> w;

        for(int i = 0; i < h; i++)
        {
            string s;
            cin >> s;

            for(int j = 0; j < w; j++)
            {
                board[i][j] = s[j];
            }
        }

        // 열쇠 저장
        string key;
        cin >> key;

        fill(hasKey, hasKey + 26, false);
        if(key != "0")
        {
            for(int i = 0; i < (int)key.size(); i++)
            {
                hasKey[key[i] - 'a'] = true;
            }
        }
        
        cout << BFS() << "\n";
    }

    return 0;
}