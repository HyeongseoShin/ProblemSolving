#include <bits/stdc++.h>

using namespace std;

#define MAX 30000000
int n, m, w;

vector<tuple<int, int, int>> edges;

bool GetAns()
{
    int dist[501];
    fill(dist, dist + n + 1, MAX);
    dist[1] = 0;

    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 0; j < (int)edges.size(); j++)
        {
            auto [s, e, t] = edges[j];
            if(dist[e] > dist[s] + t)
            {
                dist[e] = dist[s] + t;
            }
        }
    }

    for(int j = 0; j < (int)edges.size(); j++)
    {
        auto [s, e, t] = edges[j];
        if(dist[e] > dist[s] + t)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--)
    {
        cin >> n >> m >> w;

        edges.clear();
        for(int i = 0; i < m; i++)
        {
            int st, en, t;
            cin >> st >> en >> t;

            edges.push_back({st, en, t});
            edges.push_back({en, st, t});
        }

        for(int i = 0; i < w; i++)
        {
            int st, en, t;
            cin >> st >> en >> t;

            edges.push_back({st, en, -t});
        }

        if(GetAns()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}