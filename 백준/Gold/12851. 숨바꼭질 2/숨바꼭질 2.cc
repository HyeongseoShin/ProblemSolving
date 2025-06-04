#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
int pos[MAX];

int n, k;
int cnt = 0;

void BFS(int x)
{
    queue<int> q;
    q.push(x);

    pos[x] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        int nxt = cur-1;
        if(nxt >= 0 && pos[nxt] > pos[cur] + 1)
        {
            pos[nxt] = pos[cur] + 1;
            q.push(nxt);
        }

        nxt = cur+1;
        if(nxt <= 100001 && pos[nxt] > pos[cur] + 1)
        {
            pos[nxt] = pos[cur] + 1;
            q.push(nxt);
        }

        nxt = cur*2;
        if(nxt <= 100001 && pos[nxt] > pos[cur] + 1)
        {
            pos[nxt] = pos[cur] + 1;
            q.push(nxt);
        }
    }
}

void DFS(int x)
{
    if(x == n)
    {
        cnt++;
        return;
    }

    if(x - 1 >= 0 && pos[x-1] == pos[x] - 1) DFS(x-1);
    if(x + 1 <= 100001 && pos[x+1] == pos[x] - 1) DFS(x+1);
    if(x % 2 == 0 && x / 2 >= 0 && pos[x/2] == pos[x] - 1) DFS(x/2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    fill(pos, pos + MAX, INT_MAX);

    BFS(n);

    cout << pos[k] << "\n";

    DFS(k);

    cout << cnt << "\n";

    return 0;
}