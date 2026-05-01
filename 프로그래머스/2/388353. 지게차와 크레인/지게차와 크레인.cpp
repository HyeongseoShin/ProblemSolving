#include <bits/stdc++.h>

using namespace std;

int n, m;

char board[55][55];

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

int answer = 0;

// 해당하는 문자 다 지우기
void useCrain(char target)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // 컨테이너 삭제
            if(board[i][j] == target)
            {
                answer--;
                board[i][j] = '0';
            }
        }
    }
}

// 현재 컨테이너 꺼낼 수 있는지 확인 (외부에서 접근 가능한지)
bool checkPossible(int x, int y)
{
    bool vis[55][55];
    memset(vis, false, sizeof(vis));
    vis[x][y] = true;
    
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
        
            if(nX < 0 || nX >= n || nY < 0 || nY >= m) return true; // 외부 닿으면 바로 끝
            if(vis[nX][nY]) continue;
            if(board[nX][nY] != '0') continue;
            
            vis[nX][nY] = true;
            q.push({nX, nY});
        }
    }
    
    return false;
}

// 외부에 인접한 컨테이너만 꺼내기
void takeContainer(char target)
{
    vector<pair<int, int>> path;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] != target) continue;
            
            if(checkPossible(i, j)) path.push_back({i, j}); // 외부 접근 가능하면 삭제 후보 넣기
        }
    }
    
    // 삭제 가능한 컨테이너 한 번에 삭제
    for(auto [x, y] : path)
    {
        answer--;
        board[x][y] = '0';
    }
}

int solution(vector<string> storage, vector<string> requests) {
    n = (int) storage.size();
    m = (int) storage[0].size();
    
    answer = n * m; // 전체 컨테이너 수로 초기화
    
    memset(board, '0', sizeof(board));
    
    for(int i = 0; i < n; i++)
    {
        string s = storage[i];
        for(int j = 0; j < m; j++)
        {
            board[i][j] = s[j];
        }
    }
    
    
    for(int i = 0; i < (int)requests.size(); i++)
    {
        string cur = requests[i];
        
        if((int)cur.size() == 2) useCrain(cur[0]); // 크레인 사용
        else takeContainer(cur[0]); // 외부와 인접한 컨테이너만 꺼내기
    }
    
    return answer;
}