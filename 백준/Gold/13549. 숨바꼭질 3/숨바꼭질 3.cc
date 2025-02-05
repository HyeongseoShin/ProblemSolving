// https://www.acmicpc.net/problem/13549
#include <bits/stdc++.h>

using namespace std;

int n, k;
int dist[100010];

void BFS(int x)
{
    queue<int> q;

    dist[x] = 0;
    q.push(x);

    if(x == k) return;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        // cout << cur << "\n";

        if(cur == k) break;

        if(cur*2 < 100010 && dist[cur*2] == -1)
        {
            dist[cur*2] = dist[cur];
            q.push(cur*2);
        }

        if(cur-1 >= 0 && dist[cur-1] == -1)
        {
            dist[cur-1] = dist[cur] + 1;
            q.push(cur-1);
        }

        if(cur+1 < 100010 && dist[cur+1] == -1)
        {
            dist[cur+1] = dist[cur] + 1;
            q.push(cur+1);
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    fill(dist, dist + 100010, -1);

    BFS(n);

    cout << dist[k] << "\n";

    return 0;
}