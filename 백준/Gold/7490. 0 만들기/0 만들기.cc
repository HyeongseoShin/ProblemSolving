// https://www.acmicpc.net/problem/7490

// 스스로 못 풂
// 참고: https://ymthebest.tistory.com/22

// 백트래킹
#include <bits/stdc++.h>

using namespace std;

int t, n;

vector<string> ans;

// 현재 합, 이전 부호 (+ or -), 이전 값, 현재 숫자, 문자열
void Calculate(int sum, int sign, int prev, int cur, string s)
{
    if(cur == n)
    {
        sum += (prev * sign);
        if(sum == 0)
        {
            ans.push_back(s);
        }
        return;
    }

    Calculate(sum + (prev * sign), 1, cur + 1, cur + 1, s + "+" + to_string(cur + 1));
    Calculate(sum + (prev * sign), -1, cur + 1, cur + 1, s + "-" + to_string(cur + 1));
    Calculate(sum, sign, prev * 10 + cur + 1, cur + 1, s + " " + to_string(cur + 1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        Calculate(0, 1, 1, 1, "1");

        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << "\n";
        }

        cout << "\n";
        ans.clear();
    }

    return 0;
}