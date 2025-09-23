#include <bits/stdc++.h>

using namespace std;

// 톱니바퀴 상태 저장
string wheel[5];

int k;

int ans = 0;

bool isRotated[5];

// 방향에 맞게 톱니바퀴 회전하는 함수
void rotate(int num, int dir)
{
    // dir == 1 : 시계 방향
    if(dir == 1)
    {
        int tmp = wheel[num][7];

        for(int i = 6; i >= 0; i--)
        {
            wheel[num][i+1] = wheel[num][i];
        }

        wheel[num][0] = tmp;
    }

    // dir == -1 : 반시계 방향 
    else if(dir == -1)
    {
        int tmp = wheel[num][0];

        for(int i = 1; i <= 7; i++)
        {
            wheel[num][i-1] = wheel[num][i];
        }

        wheel[num][7] = tmp;
    }    
    
    // 한 번 회전했다고 표시
    isRotated[num] = true;
}

// 회전시킬 톱니바퀴 결정하는 함수 (재귀)
void divide(int num, int dir)
{
    if(isRotated[num]) return;

    int l = num - 1;
    int r = num + 1;

    bool leftPossible = false;
    bool rightPossible = false;

    // 왼쪽 톱니바퀴 (3시) - 나의 극성 확인 (9시) 후 다르면 회전
    if(l >= 1 && wheel[l][2] != wheel[num][6]) leftPossible = true;

    // 나 (3시) - 오른쪽 톱니바퀴 (9시) 극성 확인 후 다르면 회전
    if(r <= 4 && wheel[num][2] != wheel[r][6]) rightPossible = true;

    rotate(num, dir);

    // 이전에 회전한 적이 없고 회전이 가능하다면 회전
    if(!isRotated[l] && leftPossible) divide(l, dir * -1);
    if(!isRotated[r] && rightPossible) divide(r, dir * -1);

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 4; i++)
    {
        cin >> wheel[i];
    }

    cin >> k;

    while(k--)
    {
        int num, dir;

        // 톱니 번호, 방향
        cin >> num >> dir;

        // 회전했는지 확인하는 배열 초기화
        fill(isRotated, isRotated + 5, false);
        divide(num, dir);
    }

    // 각 톱니바퀴의 12시 극성에 따라 점수 계산
    for(int i = 1; i <= 4; i++)
    {
        ans += ((wheel[i][0] - '0') * (1 << (i-1)));
    }

    cout << ans << "\n";

    return 0;
}