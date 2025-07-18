#include <bits/stdc++.h>

using namespace std;

#define MAX 4000001
int n, m, k;

vector<int> minsu;

int parent[MAX];

int Find(int v)
{
    if(v == parent[v]) return parent[v];
    return parent[v] = Find(parent[v]);
}

void Union(int v1, int v2)
{
    v1 = Find(v1);
    v2 = Find(v2);

    if(v1 != v2) parent[v1] = v2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        minsu.push_back(x);
        parent[i] = i;
    }

    // 이분탐색 위한 정렬
    sort(minsu.begin(), minsu.end());

    for(int i = 0; i < k; i++)
    {
        int chulsu;
        cin >> chulsu;

        int idx = upper_bound(minsu.begin(), minsu.end(), chulsu) - minsu.begin();
        idx = Find(idx);

        cout << minsu[idx] << "\n";

        // idx를 뽑았으니
        // 다음에도 idx가 선택되면 안되므로 idx parent를 idx+1로 바꾼다
        Union(idx, idx + 1);
    }

    return 0;
}