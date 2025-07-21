#include <bits/stdc++.h>

using namespace std;

int n;

vector<string> tree[1001];

set<string> path;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        for(int j = 0; j < k; j++)
        {
            string s;
            cin >> s;

            tree[i].push_back(s);
        }
    }

    sort(tree, tree + n);

    for(int i = 0; i < n; i++)
    {
        string tmpPath = "";
        for(int j = 0; j < (int)tree[i].size(); j++)
        {
            tmpPath += tree[i][j];

            if(path.count(tmpPath) == 0)
            {
                for(int k = 0; k < j; k++) cout << "--";
                cout << tree[i][j] << "\n";
                path.insert(tmpPath);
            }
        }
    }

    return 0;
}