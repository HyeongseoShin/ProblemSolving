#include <bits/stdc++.h>

using namespace std;

int n, m;

// 다리 정보 <중량 제한, 목적지>
vector<pair<int, int>> adj[10001];

// 공장이 위치해있는 섬의 번호
int factory[2];

// weights[i] : i까지 오는 데 사용한 한 번의 이동 최대 중량
int weights[10001];

// 방문 확인 표시
// bool vis[10001];

// 한 번의 이동에서 옮길 수 있는 물품들의 중량의 최댓값 구하기
void BFS(int from, int to)
{
//    vis[from] = true;

    memset(weights, -1, sizeof(weights));
    weights[from] = INT_MAX;

    // <현재까지 최대 중량, 목적지>
    priority_queue<pair<int, int>> q;

    q.push({weights[from], from});

    while(!q.empty())
    {
        auto [curW, cur] = q.top();
        q.pop();

        if(cur == to) return;

        for(auto [nxtW, nxt] : adj[cur])
        {
            int w = min(curW, nxtW);

            if(w > weights[nxt])
            {
                weights[nxt] = w;
                q.push({w, nxt});
            }
            // // 현재까지의 최대 중량보다 더 큰 값이 나오면 불가능
            // if(curW != 0 && curW < nxtW) continue;

            // // cout << "cur: " << cur << " curW: " << curW << " nxt: " << nxt << " nxtW: " << nxtW << "\n";

            // // 이미 방문했다면 패스
            // if(vis[nxt] && nxt != to) continue;

            // int w = -1;
            // if(curW == 0) w = nxtW;
            // else w = min(curW, nxtW);

            // // 이 떄까지 지난 곳 중 가장 큰 중량으로 업데이트
            // vis[nxt] = true;
            // weights[nxt] = max(weights[nxt], w);
            // q.push({weights[nxt], nxt});

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
        int from, to, w;

        cin >> from >> to >> w;

        adj[from].push_back({w, to});
        adj[to].push_back({w, from});
    }

    for(int i = 0; i < 2; i++) cin >> factory[i];

    BFS(factory[0], factory[1]);

    cout << weights[factory[1]] << "\n";

    return 0;
}