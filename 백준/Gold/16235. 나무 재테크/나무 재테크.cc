#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int A[11][11]; // 겨울에 추가될 양분


// deque은 inde, iterator 모두 접근 가능함!
// <나무 나이, 생존 여부>
deque<int> tree[11][11];

int water[11][11]; // 양분 양 : 처음에 모두 5 들어있음

// 인접한 8방향
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int ans = 0;

// <x, y, 나이>
queue<tuple<int, int, int>> deadTrees;

void springAndSummer()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int sz = (int)tree[i][j].size();

            if(sz == 0) continue;

            deque<int> newTrees;

            int deadWater = 0;

            // 나이가 어린 나무부터 자신의 나이만큼 양분 먹음
            for(int k = 0; k < sz; k++)
            {
                int age = tree[i][j][k];

                if(water[i][j] >= age)
                {
                    water[i][j] -= age;

                    // 양분 먹으면 나이 + 1
                    newTrees.push_back(age+1); 
                }

                // 여름 : 봄에 죽은 나무가 영양분으로 변경됨
                else
                {
                    deadWater += (age / 2);
                }
            }

            water[i][j] += deadWater;
            tree[i][j] = move(newTrees);
        }
    }
}

void fall()
{
    // 나이가 5의 배수인 나무이면
    // 인접한 8개의 칸에 나이가 1인 나무가 생긴다
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int sz = (int)tree[i][j].size();

            if(sz == 0) continue;

            for(int k = 0; k < sz; k++)
            {
                int age = tree[i][j][k];

                if(age % 5 != 0) continue; 
                
                for(int dir = 0; dir < 8; dir++)
                {
                    int nX = i + dx[dir];
                    int nY = j + dy[dir];

                    if(nX < 1 || nX > n || nY < 1 || nY > n) continue;

                    tree[nX][nY].push_front(1);
                }
            }
        }
    }
}

// 겨울에는 양분 추가
void winter()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            water[i][j] += A[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    // 겨울에 추가되는 양분
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> A[i][j];

            // 양분 처음에 모두 5 들어있음
            water[i][j] = 5;
        }
    }

    // 나무 나이 입력 받음
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        tree[x][y].push_front(z);
    }

    // 해마다 진행
    while(k--)
    {
        springAndSummer();
        fall();
        winter();
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ans += (int)tree[i][j].size();
        }
    }

    cout << ans << "\n";

    return 0;
}