#include <bits/stdc++.h>

using namespace std;

#define MAX 10001

int n, m;
int mcCnt, mcMax; // 맥날 개수, 맥세권 조건
int sbCnt, sbMax; // 스벅 개수, 스세권 조건

set<int> mcPos; // 맥날 정점 번호
set<int> sbPos; // 스벅 정점 번호

vector<pair<int, int>> adj[MAX];

int mcDist[MAX];
int sbDist[MAX];

// 맥세권 or 스세권인 집 구하기
void getDist(set<int> &pos, int* dist)
{
    fill(dist, dist + MAX, 100000001);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // 시작점 세팅
    for(auto p : pos)
    {
        dist[p] = 0;
        pq.push({dist[p], p});
    }

    while(!pq.empty())
    {
        auto [curDist, cur] = pq.top();
        pq.pop();

        if(dist[cur] < curDist) continue;

        for(auto [nDist, nxt] : adj[cur])
        {
            if(dist[nxt] <= dist[cur] + nDist) continue;

            dist[nxt] = dist[cur] + nDist;
            pq.push({dist[nxt], nxt});
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    cin >> mcCnt >> mcMax;
    for(int i = 0; i < mcCnt; i++)
    {
        int x;
        cin >> x;
        mcPos.insert(x);
    }

    cin >> sbCnt >> sbMax;
    for(int i = 0; i < sbCnt; i++)
    {
        int x;
        cin >> x;
        sbPos.insert(x);
    }

    // 맥세권 구하기
    getDist(mcPos, mcDist);

    // 스세권 구하기
    getDist(sbPos, sbDist);

    // 맥세권 & 스세권 중 최단 거리 제일 작은 정답 구하기
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;

    for(int i = 1; i <= n; i++)
    {
        // 맥날 & 스벅 매장 위치면 패스
        if(mcPos.find(i) != mcPos.end()) continue;
        if(sbPos.find(i) != sbPos.end()) continue;

        // 맥세권 & 스세권 해당 안되면 패스
        if(mcDist[i] > mcMax) continue;
        if(sbDist[i] > sbMax) continue;

        pq.push({mcDist[i] + sbDist[i], i});
    }

    if(pq.empty()) cout << "-1\n";
    else cout << pq.top().first << "\n";

    return 0;
}