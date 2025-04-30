#include <bits/stdc++.h>

using namespace std;

int n, m;

int parent[51];

int trueCnt;

vector<int> party[51];
vector<int> truePeople;

int Find(int v)
{
    if(parent[v] == v) return parent[v];
    return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    
    cin >> trueCnt;

    // 진실 아는 사람 저장
    for(int i = 0; i < trueCnt; i++)
    {
        int x;
        cin >> x;

        truePeople.push_back(x);
    }

    // 각 파티 정보 저장 (같은 파티에 있는 사람끼리 Union & Find)
    for(int i = 0; i < m; i++)
    {
        int cnt;
        cin >> cnt;

        for(int j = 0; j < cnt; j++)
        {
            int x;
            cin >> x;
            party[i].push_back(x);

            if(party[i].size() > 0)
            {
                Union(party[i][0], x);
            }
        }
    }

    int cnt = 0;
    // 각 파티를 순회하며 해당 파티에 진실 아는 사람 있는지 확인 후 답 도출
    for(int i = 0; i < m; i++)
    {
        bool isPossible = true;
        for(int j = 0; j < trueCnt; j++)
        {
            if(Find(truePeople[j]) == Find(party[i][0]))
            {
                isPossible = false;
                break;
            }
        }

        if(isPossible) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}