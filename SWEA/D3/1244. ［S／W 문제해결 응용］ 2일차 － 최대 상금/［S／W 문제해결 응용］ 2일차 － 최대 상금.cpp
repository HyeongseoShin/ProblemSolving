#include <bits/stdc++.h>

using namespace std;

string s;

int n, k;

int ans;

void GetAns(int idx, int cnt)
{
    if(cnt == k)
    {
        ans = max(ans, stoi(s));
        return;
    }

    for(int i = idx; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            swap(s[i], s[j]);
            GetAns(i, cnt + 1);
            swap(s[i], s[j]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> s >> k;

        n = (int)s.length();

        if(k > n) k = n; // 시간 초과 방지
        ans = 0;
        GetAns(0, 0);
        
        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}