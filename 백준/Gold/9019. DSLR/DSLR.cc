#include <bits/stdc++.h>

using namespace std;

int t, a, b;

bool vis[10000];

void BFS()
{
    memset(vis, false, sizeof(vis));

    queue<pair<int, string>> q;
    vis[a] = true;
    q.push({a, ""});;

    while(!q.empty())
    {
        auto [cur, dir] = q.front();
        q.pop();

        if(cur == b)
        {
            cout << dir << "\n";
            return;
        }

        // D 연산 : 2n % 10000
        int nxt = (cur * 2) % 10000;
        if(!vis[nxt])
        {
            q.push({nxt, dir + "D"});
            vis[nxt] = true;
        }
        

        // S 연산 : n - 1
        nxt = cur - 1;
        if(nxt < 0) nxt = 9999;        
        if(!vis[nxt]) 
        {
            q.push({nxt, dir + "S"});
            vis[nxt] = true;
        }
        
        // L연산 (앞에껄 맨 뒤에)
        nxt = (cur % 1000) * 10 + (cur / 1000);
        if(!vis[nxt]) 
        {
            q.push({nxt, dir + "L"});
            vis[nxt] = true;
        }

        // R연산 (맨 뒤를 맨 앞에)
        nxt = cur / 10 + (cur % 10) * 1000;
        if(!vis[nxt]) 
        {
            q.push({nxt, dir + "R"});
            vis[nxt] = true;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        BFS();
    }

    return 0;
}