#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n; // 섬 개수

// x, y 좌표
ll xPos[1001];
ll yPos[1001];

int parent[1001];

// 세율
double e;

int Find(int v)
{
    if(v == parent[v]) return parent[v];
    return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);
    
    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

// 거리 구하기
double GetDist(ll x1, ll y1, ll x2, ll y2)
{
    return ((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2)) * e;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            cin >> xPos[i];
        }

        for(int i = 0; i < n; i++)
        {
            cin >> yPos[i];
        }

        cin >> e;

        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<>> pq;

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                pq.push({GetDist(xPos[i], yPos[i], xPos[j], yPos[j]), i, j});
            }
        }

        int cnt = 0;
        double ans = 0;

        while(cnt < n - 1)
        {
            auto [curDist, from, to] = pq.top();
            pq.pop();


            if(Find(from) != Find(to))
            {
                Union(from, to);
                ans += curDist;
                cnt++;
            }
        }

        cout << "#" << t << " " << (ll)round(ans) << "\n";
    }

    return 0;
}