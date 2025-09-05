#include <bits/stdc++.h>

using namespace std;

int n; // 접시 개수
int d; // 초밥 가지 수
int k; // 연속해서 먹는 접시의 수
int c; // 쿠폰번호 (공짜)

int sushi[3000001];

// 번호 별 현재 초밥 먹었는지 확인
int eaten[3001];

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;

    for(int i = 0; i < n; i++)
    {
        cin >> sushi[i];
    }

    int sz = 0;

    // 초기 슬라이딩 윈도우
    for(int i = 0; i < k; i++)
    {
        if(eaten[sushi[i]] == 0) sz++;
        eaten[sushi[i]]++;
    }

    ans = sz;
    if(eaten[c] == 0) ans++;

    for(int st = 1; st < n; st++)
    {
        int en = (st + k - 1) % n;

        // 왼쪽 제거
        eaten[sushi[st-1]]--;
        if(eaten[sushi[st-1]] == 0) sz--;

        // 오른쪽 추가
        if(eaten[sushi[en]] == 0) sz++;
        eaten[sushi[en]]++;

        if(eaten[c] == 0) ans = max(ans, sz + 1);
        else ans = max(ans, sz);
    }

    cout << ans << "\n";

    return 0;
}