#include <bits/stdc++.h>

using namespace std;

int n;

int parent[101];

pair<double, double> pos[101];

priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<>> pq;

int Find(int v)
{
    if(parent[v] == v) return parent[v];
    else return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

double GetDist(double x1, double y1, double x2, double y2)
{
    return sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;

        pos[i] = {x, y};
        parent[i] = i;
    }

    for(int i = 0; i < n - 1; i++)
    {
        auto [x1, y1] = pos[i];
        for(int j = i + 1; j < n; j++)
        {
            auto [x2, y2] = pos[j];
            pq.push({GetDist(x1, y1, x2, y2), i, j});
        }
    }

    int cnt = 0;
    double ans = 0;

    while(cnt < n - 1)
    {
        auto [dist, u, v] = pq.top();
        pq.pop();

        if(Find(u) != Find(v))
        {
            Union(u, v);
            ans += dist;
            cnt++;
        }
    }

    cout << fixed;
    cout.precision(2);

    cout << ans << "\n";

    return 0;
}