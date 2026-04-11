#include <bits/stdc++.h>

using namespace std;

// 원판 , 정수, 테스트 수
int n, m, t;

int board[51][51];

// 회전 방법
// 번호 => x배수인 원판
// d => 방향 0: 시계, 1: 반시계
// k 칸만큼
int x, d, k;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void printBoard()
{
    cout << "\n========Board==========\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// 원판 회전
void rotateBoard(int idx, int dir, int cnt)
{
    int tmpBoard[51];
    memcpy(tmpBoard, board[idx], sizeof(board[idx]));

    int step = 1;
    // 반시계 방향
    if(dir == 1) step = -1;

    for(int i = 0; i < m; i++)
    {
        int nxt = (i + (k * step)) % m;
        if(nxt < 0) nxt += m;

        board[idx][nxt] = tmpBoard[i];
    }
}

double getAvg()
{
    double result = 0.0;
    int sum = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0) continue;
            sum += board[i][j];
            cnt++;
        }
    }

    result = (double) sum / (double) cnt;

    return result;
}

void check()
{
    bool isDeleted = false;
    vector<pair<int, int>> deletePos;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0) continue;

            bool isSame = false;
            for(int dir = 0; dir < 4; dir++)
            {
                int nX = i + dx[dir];
                int nY = (j + dy[dir]) % m;
                if(nY < 0) nY += m;

                if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
                if(board[nX][nY] == board[i][j])
                {
                    deletePos.push_back({nX, nY});
                    isSame = true;
                    isDeleted = true;
                }
            }

            if(isSame) deletePos.push_back({i, j});
        }
    }

    // 한 꺼번에 모아서 지우기
    for(auto [delX, delY] : deletePos) board[delX][delY] = 0;
    

    if(!isDeleted)
    {
        double avg = getAvg();
        // cout << "avg: " << avg << "\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 0) continue;
                if((double)board[i][j] > avg) board[i][j]--;
                else if((double)board[i][j] < avg) board[i][j]++;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < t; i++)
    {
        cin >> x >> d >> k;

        for(int j = (x - 1); j < n; j += x) rotateBoard(j, d, k);        
        check();

        // printBoard();
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans += board[i][j];
        }
    }

    cout << ans << "\n";

    return 0;
}