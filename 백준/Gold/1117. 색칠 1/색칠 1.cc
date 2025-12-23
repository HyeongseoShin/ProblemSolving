#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll w, h, f, c, lX, lY, rX, rY;

ll painted = 0; // 색칠된 곳

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h >> f >> c >> lX >> lY >> rX >> rY;

    // 처음 접혀져 있는 거 + 가로로 c번 접은 거
    painted = (rX - lX) * (rY - lY) * (c+1);

    // 세로로 접었을 때
    // 얼만큼 겹쳐졌는지 확인 How??

    // 왼쪽 크기 <= 오른쪽 크기
    if(f <= w / 2)
    {
        ll overlap = min(f, rX) - lX;
        if(overlap > 0) painted += overlap * (rY - lY) * (c + 1);
    }

    // 왼쪽 크기 > 오른쪽 크기
    else
    {
        ll overlap = min(w, f + rX) - (f + lX);
        if(overlap > 0) painted += overlap * (rY - lY) * (c + 1);
    }

    cout << w*h - painted << "\n";
    
    return 0;
}