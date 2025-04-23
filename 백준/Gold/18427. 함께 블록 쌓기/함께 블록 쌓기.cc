#include <bits/stdc++.h>

using namespace std;

int n, m, h;

// dp[k][n] : k번 학생까지 봤을 때 탑 높이가 n인 경우의 수
int dp[55][1001];

vector<int> blocks[55];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);

        // 공백 기준 split
        stringstream sstr(s);

        int num;
        while(sstr >> num) blocks[i].push_back(num);
    }

    // dp 배열 초기화
    // 높이가 0인 경우는 모두 존재 (안 골랐을 때)
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    // dp 작성
    for(int i = 1; i <= n; i++)
    {
        // 만들 수 있는 높이 1 ~ h까지 확인
        for(int j = 1; j <= h; j++)
        {
            // 현재 학생의 블록 순회
            for(int k = 0; k < (int)blocks[i].size(); k++)
            {
                int curH = blocks[i][k];

                // 현재 블록 이전까지 쌓은 높이와 비교 후 가능하면 쌓기
                if(j - curH >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j - curH]) % 10007;
            }

            // 현재 학생이 블록을 안 썼을 때
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[n][h] << "\n";

    return 0;

}