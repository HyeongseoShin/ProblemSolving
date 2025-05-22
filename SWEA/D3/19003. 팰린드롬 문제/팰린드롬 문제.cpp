#include <bits/stdc++.h>

using namespace std;

vector<string> v;

int n, m;

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> n >> m;

        v.clear();
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            v.push_back(s);
        }

        // 가장 긴 팰린드롬 찾기
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int l = 0;
            int r = (int)v[i].length() - 1;

            while(l <= r && v[i][l] == v[i][r])
            {
                l++;
                r--;
            }

            // cout << "l: " << l << " r:" << r << "\n";
            if(l > r) ans = max(ans, (int)v[i].length());
        }

        bool isUsed[101];
        fill(isUsed, isUsed + 101, false);

        // 현재 문자열과 짝이 되는 문자열이 있는지 확인
        for(int i = 0; i < n - 1; i++)
        {
            if(isUsed[i]) continue;

            string tmp = v[i];
            reverse(tmp.begin(), tmp.end());

            for(int j = i + 1; j < n; j++)
            {
                if(tmp == v[j])
                {
                    isUsed[i] = true;
                    isUsed[j] = true;

                    ans += ((int)v[i].length() * 2);
                }
            }
        }
        
        cout << "#" << t << " " << ans << "\n";
    }

    
    return 0;
}