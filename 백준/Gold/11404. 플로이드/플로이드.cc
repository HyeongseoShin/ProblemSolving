#include <bits/stdc++.h>

using namespace std;

int n, m;

const int INF = 0x3f3f3f3f;

int dist[105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        fill(dist[i], dist[i] + 1 + n, INF);
    }

    while(m--)
    {
        int a, b, c;

        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == j)
                {
                    continue;
                }
                
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dist[i][j] == INF)
            {
                cout << "0 ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}