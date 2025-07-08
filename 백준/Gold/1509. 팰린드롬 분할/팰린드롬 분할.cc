#include <bits/stdc++.h>

using namespace std;

string s;
int n;

// dp[i] : 0 ~ i까지 팰린드롬 분할의 개수의 최솟값
int dp[2501];

// isPalindrome[i][j] : i ~ j까지 팰린드롬이면 true
bool isPalindrome[2501][2501];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    n = (int) s.length();

    // 부분 문자열 팰린드롬 여부 미리 저장
    // 부분 문자열 길이만큼 (1 ~ n)
    for(int len = 1; len <= n; len++)
    {
        // 시작 인덱스
        for(int i = 0; i <= n - len; i++)
        {
            // 끝 인덱스
            int j = i + len - 1;

            if(len == 1) isPalindrome[i][j] = true;
            else if(len == 2 && s[i] == s[j]) isPalindrome[i][j] = true;
            
            // 양 쪽 끝이 같고
            // 안쪽이 팰린드롬이면 팰린드롬
            else if(len > 2 && s[i] == s[j] && isPalindrome[i+1][j-1]) isPalindrome[i][j] = true;
        }
    }

    // DP 진행
    for(int i = 0; i < n; i++)
    {
        dp[i] = i + 1; // 초기화
        for(int j = 0; j <= i; j++)
        {
            if(isPalindrome[j][i]) {
                // 처음 ~ i까지 팰린드롬이면 그냥 1
                if(j == 0) dp[i] = 1;

                // 아니면 현재 시작점 -1 의 최소분할개수 + 1
                else dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    cout << dp[n-1] << "\n";

    
    


    return 0;
}