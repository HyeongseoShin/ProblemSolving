#include <bits/stdc++.h>

using namespace std;

int n, k;
int dist[100010];

void BFS(int x)
{
    queue<int> q;

    dist[x] = 0;
    q.push(x);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(cur*2 < 100010 && dist[cur*2] == -1)
        {
            dist[cur*2] = dist[cur];
            q.push(cur*2);
        }

        if(cur*2 == k)
        {
            cout << dist[cur] << "\n";
            return;
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

        if(cur + 1 == k || cur - 1 == k)
        {
            cout << dist[cur] + 1 << "\n";
            return;
        }

        
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    if(n == k)
    {
        cout << "0\n";
        return 0;
    }

    fill(dist, dist + 100010, -1);

    BFS(n);

    return 0;
}