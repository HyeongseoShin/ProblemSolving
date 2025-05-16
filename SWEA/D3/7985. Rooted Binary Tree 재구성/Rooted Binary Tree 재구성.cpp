#include <bits/stdc++.h>

using namespace std;

int k;
int tree[1100];
int n;
vector<int> level[10];

void DivideTree(int st, int en, int depth)
{
    if(st > en) return;

    int mid = (st + en) / 2;
    level[depth].push_back(tree[mid]);

    DivideTree(st, mid - 1, depth + 1);
    DivideTree(mid + 1, en, depth + 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        cin >> k;

        n = pow(2, k) - 1;

        for(int i = 0; i < n; i++)
        {
            cin >> tree[i];
        }

        for(int i = 0; i < 10; i++)
        {
            level[i].clear();
        }

        DivideTree(0, n, 0);

        cout << "#" << t << " ";
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < (int)level[i].size(); j++)
            {
                cout << level[i][j] << " ";
            }
            cout << "\n";
        }

    }

    return 0;
}