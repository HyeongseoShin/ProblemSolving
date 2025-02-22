// https://www.acmicpc.net/problem/2179
#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

string s;
string t;

int maxLen = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        v.push_back(input);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(v[i] == v[j]) continue;

            int idx = 0;
            int cnt = 0;

            while(idx < v[i].length() && v[i][idx] == v[j][idx])
            {
                idx++;
                cnt++;
            }

            if(cnt > maxLen)
            {
                s = v[i];
                t = v[j];
                maxLen = cnt;
            }
        }
    }

    cout << s << "\n";
    cout << t << "\n";

    return 0;
}