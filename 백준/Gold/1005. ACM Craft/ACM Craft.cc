#include <bits/stdc++.h>

using namespace std;

int t, n, k, w;

int d[1001]; // 각 건물 건설 시간
int inDegree[1001]; // 진입 차수 (위상 정렬)
vector<int> adj[1001]; // 건설 순서 그래프
int dp[1001]; // dp[i] : i번째 건물 짓기까지 걸리는 최소 시간

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 1; i <= n; i++)
        {
            cin >> d[i];
            adj[i].clear();
            inDegree[i] = 0;
            dp[i] = 0;
        }

        while(k--)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            inDegree[v]++; // 위상 정렬 위해 진입 차수 ++ (먼저 지어져야 할 건물 수)
        }

        cin >> w;

        queue<int> q;

        // 먼저 지을 수 있는 건물 큐에 삽입
        for(int i = 1; i <= n; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
                dp[i] = d[i];
            }   
        }

        // 위상 정렬
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            for(int nxt : adj[cur])
            {
                dp[nxt] = max(dp[nxt], dp[cur] + d[nxt]);

                inDegree[nxt]--;
                if(inDegree[nxt] == 0)
                {
                    q.push(nxt);
                }
            }
        }
        

        cout << dp[w] << "\n";
    }
    
    return 0;
}