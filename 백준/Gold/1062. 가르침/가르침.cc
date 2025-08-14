#include <bits/stdc++.h>

using namespace std;

// 해당 알파벳 읽을 수 있는지
set<char> isReadable;

int n, k;
vector<string> v;

int ans = 0;

int GetCnt()
{
    int cnt = 0;
    for(auto s : v)
    {
        bool isPossible = true;
        for(int i = 0; i < (int)s.length(); i++)
        {
            if(isReadable.count(s[i]) == 0)
            {
                isPossible = false;
                break;
            }
        }

        if(isPossible) cnt++;
    }

    return cnt;
}
void GetAns(char cur, int cnt)
{
    if(cnt == k)
    {
        ans = max(ans, GetCnt());
        return;
    }

    for(char c = cur; c <= 'z'; c++)
    {
        if(isReadable.count(c) > 0) continue;
        isReadable.insert(c);
        GetAns(c, cnt + 1);
        isReadable.erase(c);
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    // 가르칠 문자 개수가 5보다 작으면 아예 불가능
    if(k < 5)
    {
        cout << "0\n";
        return 0;
    }

    // anta ~ tica : a, n, t, i, c는 무조건 가르쳐야 함
    isReadable.insert('a');
    isReadable.insert('n');
    isReadable.insert('t');
    isReadable.insert('i');
    isReadable.insert('c');

    k -= 5;

    GetAns('b', 0);

    cout << ans << "\n";

    

    return 0;
}