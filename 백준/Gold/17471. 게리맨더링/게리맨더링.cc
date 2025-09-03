#include <bits/stdc++.h>

using namespace std;

int n; // 구역 개수
int people[11]; // 구역에 사는 인구 수 (1 ~ 100)

int ans = INT_MAX;

bool adj[11][11]; // 인접한 구역 표시

int parent[11]; // 선거구 번호 (0 or 1)

// 각 선거구 별로 BFS 진행해서 모두 연결되어있는지 확인
int BFS(int from, int num)
{
    bool vis[11];

    fill(vis, vis + 11, false);
    
    // 0번 선거구부터 진행
    queue<int> q;
    q.push(from);
    vis[from] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i = 1; i <= n; i++)
        {
            // 연결 안 되어있으면 패스
            if(!adj[cur][i]) continue;

            // 다른 선거구이면 패스
            if(parent[i] != num) continue;

            // 이미 방문했으면 패스
            if(vis[i]) continue;

            vis[i] = true;
            q.push(i);
        }
    }

    int p = 0;

    // 모두 연결되어있는지 확인
    for(int i = 1; i <= n; i++)
    {
        if(parent[i] == num) 
        {
            if(!vis[i]) return INT_MAX; 
            else p += people[i]; 
        }
        
    }

    return p;
}

// 두 선거구로 나눌 수 있는 조합 찾기
void Divide(int idx, int cur, int max)
{
    if(cur == max)
    {
        int from0 = -1, from1 = -1;
        // 각 선거구 별 출발지 뽑기
        for(int i = 1; i <= n; i++)
        {
            if(from0 != -1 && from1 != -1) break;

            if(parent[i] == 0) from0 = i;
            else if(parent[i] == 1) from1 = i;
        }

        int result0 = BFS(from0, parent[from0]);
        int result1 = BFS(from1, parent[from1]);

        if(result0 != INT_MAX && result1 != INT_MAX) 
        {
            ans = min(ans, abs(result0 - result1));
        }
        return;
    }

    // 조합 뽑기
    for(int i = idx; i <= n; i++)
    {
        if(parent[i] == 0)
        {
            parent[i] = 1;
            Divide(i + 1, cur + 1, max);
            parent[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> people[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int cnt;

        cin >> cnt;

        while(cnt--)
        {
            int near;
            cin >> near;

            // 양방향 그래프
            adj[i][near] = true;
            adj[near][i] = true;
        }
    }

    // 두 구역으로 나누기
    for(int i = 1; i <= n / 2; i++)
    {
        Divide(1, 0, i);
    }

    if(ans == INT_MAX) ans = -1;

    cout << ans << "\n";



    return 0;
}