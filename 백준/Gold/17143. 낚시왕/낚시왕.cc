#include <bits/stdc++.h>

using namespace std;

int r, c, m;

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

// <크기 , 속력, 방향>
tuple<int, int, int> beforeShark[101][101]; // 이동 전 상어
priority_queue<tuple<int, int, int>> afterShark[101][101]; // 이동 후 상어

int ans = 0;

void MoveShark()
{
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            // (크기, 속력, 방향)
            auto [z, s, d] = beforeShark[i][j];

            // 방향 0이면 상어 없음
            if(d == 0) continue;

            int nX = i, nY = j;
            int tmpS = s;

            if(d == 1 || d == 2) tmpS %= 2 * (r - 1);
            else tmpS %= 2 * (c - 1);

            while(tmpS--)
            {
                int nx = nX + dx[d];
                int ny = nY + dy[d];

                if(nx < 1 || nx > r || ny < 1 || ny > c)
                {
                    if(d == 1 || d == 3) d++;
                    else d--;
                    
                    nx = nX + dx[d];
                    ny = nY + dy[d];
                }

                nX = nx;
                nY = ny;
            }

            // cout << "nX: " << nX << " nY: " << nY << "\n";

            // 원래 지점 상어 없어짐
            beforeShark[i][j] = {0, 0, 0};

            // 새로운 곳에 상어 추가
            afterShark[nX][nY].push({z, s, d});
        }
    }

    // afterShark -> beforeShark로 복사
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(afterShark[i][j].empty()) continue;

            beforeShark[i][j] = afterShark[i][j].top();

            while(!afterShark[i][j].empty()) afterShark[i][j].pop();
        }
    }

    // cout << "\n=======Before Shark=======\n";
    // // BeforeShark
    // for(int i = 1; i <= r; i++)
    // {
    //     for(int j = 1; j <= c; j++)
    //     {
    //         auto [z, s, d] = beforeShark[i][j];
    //         cout << z << " ";
    //     }
    //     cout << "\n";
    // }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> m;

    // 상어 위치, 속력, 방향, 크기 저장
    for(int i = 0; i < m; i++)
    {
        int rPos, cPos, s, d, z;

        cin >> rPos >> cPos >> s >> d >> z;

        // <크기, 속력, 방향>
        beforeShark[rPos][cPos] = {z, s, d};
    }

    
    // 1. 낚시와 오른쪽으로 한 칸 이동
    for(int i = 1; i <= c; i++)
    {
        // 2. 낚시왕이 현재 열에 있는 상어 중 땅과 제일 가까운 상어 잡음
        for(int j = 1; j <= r; j++)
        {
            // <크기, 속력, 방향>
            auto [z, s, d] = beforeShark[j][i];

            // 방향이 0이면 상어 없음
            if(d == 0) continue;

            // cout << "z: " << z << " s: " << s << " d: " << d << "\n";

            // 상어 잡고 상어 사라짐
            ans += z;
            beforeShark[j][i] = {0, 0, 0};

            break;
        }

        // 3. 상어 이동
        MoveShark();
    }
    
    cout << ans << "\n";

    return 0;
}