#include <bits/stdc++.h>

using namespace std;

int n, m, k;

// 겨울 양분 추가 값
int A[11][11];

// 각 위치에 나무 나이
deque<int> trees[11][11];

// 각 위치에 있는 양분
int food[11][11];

// 8방향
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 디버깅용
void printTrees()
{
    cout << "\n==============Trees Size====================\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << (int)trees[i][j].size() << " ";
        }
        cout << "\n";
    }
}

// 디버깅용
void printFood()
{
    cout << "\n==============Food====================\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << food[i][j] << " ";
        }
        cout << "\n";
    }
}

// 1. 봄 - 나무가 양분 먹방
//    여름 - 죽은 나무가 양분으로 변함
void springAndSummer()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int sz = (int)trees[i][j].size();
            if(sz == 0) continue; // 나무 없으면 패스

            deque<int> tmp;
            int deadFood = 0;
            for(int l = 0; l < sz; l++)
            {
                int curAge = trees[i][j][l];

                // 나무 사망하면 양분으로 변함 (여름)
                if(food[i][j] < curAge) deadFood += (curAge / 2);
                else
                {
                    food[i][j] -= curAge;
                    tmp.push_back(curAge + 1);
                }
            }

            food[i][j] += deadFood;
            // 살아 남은 나무만 다시 넣음
            trees[i][j] = tmp;
        }
    }
}

// 2. 가을 - 5의 배수인 나무 8방향에 나이 1인 나무 생김
void fall()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int sz = (int)trees[i][j].size();

            if(sz == 0) continue;

            for(int l = 0; l < sz; l++)
            {
                int curAge = trees[i][j][l];

                // 나무 나이가 5의 배수 => 8방향에 나이 1인 나무 생김
                if(curAge % 5 == 0)
                {
                    for(int dir = 0; dir < 8; dir++)
                    {
                        int nX = i + dx[dir];
                        int nY = j + dy[dir];

                        if(nX < 1 || nX > n || nY < 1 || nY > n) continue; // 범위 넘으면 패스

                        trees[nX][nY].push_front(1); // 새로 생긴 나무는 앞에 삽입
                    }
                }
            }
        }
    }
}


// 4. 겨울 - 양분 A만큼 추가
void winter()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            food[i][j] += A[i][j];
        }
    }
}

// 5. 정답 출력
int getAns()
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ans += (int)trees[i][j].size();
        }
    }

    return ans;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
        }
    }

    // 나무 위치 시키기
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        trees[x][y].push_back(z);
    }

    // 처음에 모든 양분 5
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            food[i][j] = 5;
        }
    }

    while(k--)
    {
        // 1. 봄 & 여름 한 번에 처리
        springAndSummer();

        // printTrees();
        // printFood();

        // 2. 가을
        fall();

        // 3. 겨울
        winter();
    }

    // 5. 정답 출력
    int ans = getAns();
    cout << ans << "\n";

    return 0;
}