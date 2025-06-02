#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[801];

int n, e;

int pos1, pos2;

int distPos1[801];
int distPos2[801];

void BFS(int x, int* dist)
{
    priority_queue<pair<int, int>> pq;

    dist[x] = 0;
    pq.push({dist[x], x});

    while(!pq.empty())
    {
        auto [curDist, cur] = pq.top();
        pq.pop();

        for(auto [nxtDist, nxt] : adj[cur])
        {
            if(dist[nxt] > dist[cur] + nxtDist)
            {
                dist[nxt] = dist[cur] + nxtDist;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cin >> pos1 >> pos2;

    fill(distPos1, distPos1 + 801, INT_MAX);
    fill(distPos2, distPos2 + 801, INT_MAX);

    BFS(pos1, distPos1);
    BFS(pos2, distPos2);

    bool isPossible1 = true, isPossible2 = true;
    int ansPos1, ansPos2;

    if(distPos1[1] != INT_MAX && distPos1[pos2] != INT_MAX && distPos2[n] != INT_MAX)
    {
        ansPos1 = distPos1[1] + distPos1[pos2] + distPos2[n];
    }
    else isPossible1 = false;

    if(distPos2[1] != INT_MAX && distPos2[pos1] != INT_MAX && distPos1[n] != INT_MAX)
    {
        ansPos2 = distPos2[1] + distPos2[pos1] + distPos1[n];
    }
    else isPossible2 = false;
    
    if(!isPossible1 && !isPossible2) cout << "-1\n";
    else if(!isPossible1) cout << ansPos2 << "\n";
    else if(!isPossible2) cout << ansPos1 << "\n";
    else cout << min(ansPos1, ansPos2) << "\n";

    return 0;
}