#include <bits/stdc++.h>

using namespace std;

int T;

// 교차로, 도착로, 목적지 후보 개수
int n, m, t;

// 출발지, 교차로 출발, 교차로 도착
int s, g, h;

// 가능한 목적지 후보
int x[101];

// 인접 리스트 <비용, 도착점>
vector<pair<int, int>> adj[2001];

// 시작점부터 다른 정점까지의 최단 거리 저장
int distS[2001];

// G부터 다른 정점까지의 최단 거리 저장
int distG[2001];

// H부터 다른 정점까지의 최단 거리 저장
int distH[2001];

// g - h 간 거리
int gh;

// 정답 배열
vector<int> ans;

void Dijkstra(int from, int* dist)
{
    // 다익스트라 위해 dist 초기화
    for(int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    // <현재까지의 거리, 현재 정점>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[from] = 0;

    pq.push({dist[from], from});

    while(!pq.empty())
    {
        auto [curDist, cur] = pq.top();
        pq.pop();

        for(auto [nxtDist, nxt] : adj[cur])
        {
            if(dist[nxt] > curDist + nxtDist)
            {
                dist[nxt] = curDist + nxtDist;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--)
    {
        cin >> n >> m >> t;

        cin >> s >> g >> h;

        // 인접 리스트 초기화
        for(int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }

        for(int i = 0; i < m; i++)
        {
            int a, b, d;

            cin >> a >> b >> d;

            adj[a].push_back({d, b});
            adj[b].push_back({d, a});

            //g - h간 거리 저장
            if((a == g && b == h) || (a == h && b == g)) gh = d;
        }

        for(int i = 0; i < t; i++)
        {
            cin >> x[i];
        }

        Dijkstra(s, distS);
        Dijkstra(g, distG);
        Dijkstra(h, distH);

        sort(x, x + t);
        for(int i = 0; i < t; i++)
        {
            int goal = x[i];

            if(distS[goal] == INT_MAX) continue;

            // distS[goal] == distS[g] + gh + distH[goal] or
            // distS[goal] == distS[h] + gh + distG[goal] 이면 경로 사용한 것
            if(distS[goal] == distS[g] + gh + distH[goal] || 
            distS[goal] == distS[h] + gh + distG[goal]) cout << goal << " ";
        }

        cout << "\n";
    }

    return 0;
}