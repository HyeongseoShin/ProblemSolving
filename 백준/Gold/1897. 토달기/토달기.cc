#include <bits/stdc++.h>

using namespace std;

int d;
string s;
string ans;

unordered_set<string> dict; // 사전에 있는 단어들

void BFS()
{
    queue<string> q;
    q.push(s);
    dict.erase(s); // 방문 확인 표시

    while(!q.empty())
    {
        string cur = q.front();
        q.pop();

        for(int i = 0; i <= (int)cur.length(); i++)
        {
            for(char j = 'a'; j <= 'z'; j++)
            {
                string nxt = cur;
                string tmp = "";
                tmp += j;
                nxt.insert(i, tmp);

                if(dict.count(nxt) == 0) continue;
                
                q.push(nxt);
                dict.erase(nxt);

                if((int)ans.length() < (int)nxt.length()) ans = nxt;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> d >> s;

    ans = s;

    for(int i = 0; i < d; i++)
    {
        string word;
        cin >> word;

        dict.insert(word);
    }

    BFS();

    cout << ans << "\n";

    return 0;
}