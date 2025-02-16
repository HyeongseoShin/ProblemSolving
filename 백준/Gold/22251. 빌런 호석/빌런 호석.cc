// https://www.acmicpc.net/problem/22251

// 스스로 못 풀었음 : 완전 탐색
// 코드 참고 : https://astrid-dm.tistory.com/444
// 현재의 수에서 1 ~ p개 LED 바꿔가며 가능한 층 구하기 ==> X
// 1 ~ N층 탐색하며 현재 층에서 목표층으로 바꿨을 때 바꾼 LED 개수가 p개 이하이면 정답 추가 ==> O

#include <bits/stdc++.h>

using namespace std;

// n층 까지
// k 자릿수
// p 최소 1개 최대 P개 반전가능
// x 현재 층
int n, k, p, x;

int ans = 0;

int curFloor [6][7];

int numLED[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> p >> x;

    for(int i = 1; i <= n; i++)
    {
        if(i == x) continue; // 현재 층은 Pass

        int cur = x, dst = i; // 현재 층은 x 목적지는 i층
        int cnt = 0; // 바꾼 LED 개수
        
        for(int j = 0; j < k; j++) // 각 자릿수 확인
        {
            for(int l = 0; l < 7; l++) // LED 7자리 확인
            {
                // cur 현재 자리의 LED와 dst 현재 자리의 LED가 다르면 반전시켜야 하므로 cnt++
                if(numLED[cur % 10][l] != numLED[dst % 10][l]) cnt++;
            }

            // 자릿수 이동
            cur /= 10;
            dst /= 10;
        }

        // cur을 dst로 바꾸는 데 LED를 P개 이하로 바꾸면 정답++
        if(cnt <= p) 
        {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}