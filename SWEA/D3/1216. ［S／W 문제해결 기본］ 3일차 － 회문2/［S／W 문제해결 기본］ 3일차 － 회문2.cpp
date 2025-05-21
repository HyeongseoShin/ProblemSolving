#include <bits/stdc++.h>

using namespace std;

vector<string> v;

int ans = 1;

void GetMaxPalindrome(string s)
{
    // 홀수 길이
    for(int i = 0; i < 100; i++)
    {
        int l = i;
        int r = i;

        while(l >= 0 && r < 100 && s[l] == s[r])
        {
            ans = max(ans, r - l + 1);

            l--;
            r++;
        }
    }

    // 짝수 길이
    for(int i = 0; i < 99; i++)
    {
        int l = i;
        int r = i + 1;

        while(l >= 0 && r < 100 && s[l] == s[r])
        {
            ans = max(ans, r - l + 1);

            l--;
            r++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin >> n;

        v.clear();

        for(int i = 0; i < 100; i++)
        {
            string s;
            cin >> s;

            v.push_back(s);
        }

        ans = 1;
        // 가로 회문 찾기
        for(auto s : v)
        {
            GetMaxPalindrome(s);
        }

        // 세로 회문 찾기
        for(int i = 0; i < 100; i++)
        {
            string tmp = "";
            for(int j = 0; j < 100; j++)
            {
                tmp += v[j][i];
            }

            GetMaxPalindrome(tmp);
        }

        cout << "#" << n << " " << ans << "\n";
    }

    return 0;
}