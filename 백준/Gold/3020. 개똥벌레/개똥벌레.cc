#include <bits/stdc++.h>

using namespace std;

int n, h;

int cave[200002]; // 각 석순 / 종유석 높이

int ans[500001]; // 각 높이별 부수는 (석순 / 종유석) 개수

pair<int, int> destroyH[200002]; // 각 석순 / 종유석이 파괴되는 높이 구간

// 각 석순 / 종유석 별 파괴될 수 있는 높이 구간 구하기
void updateDestroyH(int idx, int cur)
{
    int minH = 0;
    int maxH = 0;

    // 석순 (땅에서 솟아남)
    if(idx % 2 == 1)
    {
        minH = 1;
        maxH = cur;
    }

    // 종유석 (천장에서 내려옴)
    else
    {
        maxH = h;
        minH = (h - cur) + 1;
    }

    destroyH[idx] = {minH, maxH};

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;

    for(int i = 1; i <= n; i++)
    {
        cin >> cave[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int cur = cave[i];
        updateDestroyH(i, cur); // 각 (석순 / 종유석 별) 파괴되는 구간 구하기

        auto [minH, maxH] = destroyH[i];

        // 누적합 고려해서
        ans[minH]++; // 최소 높이: +1
        ans[maxH+1]--; // 최대 높이+1 : -1
    }

    // 누적합을 통해서 각 높이별 부술 수 있는 (석순 / 종유석) 개수 구하기
    for(int i = 2; i <= h; i++)
    {
        ans[i] += ans[i-1];
    }

    // 파괴될 수 있는 (석순 / 종유석)의 최소개수
    int minCnt = *min_element(ans+1, ans+h+1);

    // 높이 구간 구하기
    int minRange = 0;
    for(int i = 1; i <= h; i++)
    {
        if(ans[i] == minCnt) minRange++;
    }

    cout << minCnt << " " << minRange << "\n";

    return 0;
}