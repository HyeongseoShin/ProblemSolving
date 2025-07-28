#include <bits/stdc++.h>

using namespace std;

vector<char> v;

int l, c;

bool isUsed[15];

void GetAns(string cur, int idx, int len)
{
    if(len == l)
    {
        int cnt = 0;
        for(int i = 0; i < (int)cur.length(); i++)
        {
            if(cur[i] == 'a' || cur[i] == 'e' || cur[i] == 'i' || cur[i] == 'o' || cur[i] == 'u') cnt++;
        }

        if(cnt >= 1 && (int)cur.length() - cnt >= 2) cout << cur << "\n";
        
        return;
    }

    for(int i = idx; i < c; i++)
    {
        if(isUsed[i]) continue;
        
        isUsed[i] = true;
        GetAns(cur + v[i], i+1, len + 1);
        isUsed[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;

    for(int i = 0; i < c; i++)
    {
        char c;
        cin >> c;
        v.push_back(c);
    }

    sort(v.begin(), v.end());

    GetAns("", 0, 0);

    return 0;
}