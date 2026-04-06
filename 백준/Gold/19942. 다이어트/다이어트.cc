#include <bits/stdc++.h>

using namespace std;

int n;
int mp, mf, ms, mv; // 단백질, 지방, 탄수화물, 비타민
int food[16][5]; // 단백질, 지방, 탄수화물, 비타민, 비용

bool isSelected[16]; // 백트래킹 선택됐는지 확인
int ans = INT_MAX;
bool ansIdx[16];

// <인덱스 번호, 현재 비용, 현재 단백질, 현재 지방, 현재 탄수화물, 현재 비타민>
void getAns(int idx, int curP, int curF, int curS, int curV, int curCost)
{

    if(curP >= mp && curF >= mf && curS >= ms && curV >= mv)
    {
        // 현재 정답보다 더 작으면 정답 업데이트
        if(ans > curCost)
        {
            ans = curCost;
            
            // 정답 배열 업데이트
            for(int i = 1; i <= n; i++) ansIdx[i] = isSelected[i];
        }
    }
        
    // 범위 넘어서면 끝
    if(idx > n)
    {   
        return;
    }

    // 선택 O
    isSelected[idx] = true;
    getAns(idx+1, curP + food[idx][0], curF + food[idx][1], curS + food[idx][2], curV + food[idx][3], curCost + food[idx][4]);

    // 선택 X
    isSelected[idx] = false;
    getAns(idx+1, curP, curF, curS, curV, curCost);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    // 식재료 번호 1부터 시작
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> food[i][j];
        }
    }

    getAns(1, 0, 0, 0, 0, 0);

    if(ans == INT_MAX) ans = -1;
    cout << ans << "\n";

    if(ans == -1) return 0;

    for(int i = 1; i <= n; i++)
    {
        if(ansIdx[i]) cout << i << " ";
    }
    cout << "\n";

    return 0;
}