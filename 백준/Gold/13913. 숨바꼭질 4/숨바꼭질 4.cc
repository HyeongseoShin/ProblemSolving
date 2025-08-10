#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
int n, k;

int dist[MAX];
int p[MAX]; // 경로 저장

void BFS()
{
    queue<int> q;
    q.push(n);

    fill(dist, dist + MAX, INT_MAX);

    dist[n] = 0;
    p[n] = n;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(auto nxt : {cur-1, cur+1, cur*2})
        {
            if(nxt < 0 || nxt >= MAX) continue;

            if(dist[nxt] > dist[cur] + 1)
            {
                dist[nxt] = dist[cur] + 1;
                p[nxt] = cur;
                q.push(nxt);
            }
        }
    }


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    BFS();

    cout << dist[k] << "\n";

    vector<int> path;
    int cur = k;

    while(cur != n)
    {
        path.push_back(cur);
        cur = p[cur];
    }

    path.push_back(cur);

    reverse(path.begin(), path.end());

    for(auto x : path)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}