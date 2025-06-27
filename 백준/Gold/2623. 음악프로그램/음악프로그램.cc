#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> adj[1001];
int inDegree[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(m--)
    {
        int cnt;
        cin >> cnt;

        int prev;

        for(int i = 0; i < cnt; i++)
        {
            int x;
            cin >> x;

            if(i > 0)
            {
                adj[prev].push_back(x);
                inDegree[x]++;
            }

            prev = x;
        }
    }

    queue<int> q;

    for(int i = 1; i <= n; i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        ans.push_back(cur);

        for(auto nxt : adj[cur])
        {
            inDegree[nxt]--;

            if(inDegree[nxt] == 0) q.push(nxt);
        }
    }

    if((int)ans.size() < n) cout << "0\n";
    else
    {
        for(int x : ans) cout << x << "\n";
    }


    return 0;
}