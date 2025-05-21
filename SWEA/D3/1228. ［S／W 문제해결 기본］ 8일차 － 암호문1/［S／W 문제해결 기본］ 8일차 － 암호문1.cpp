#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin >> n;

        vector<int> v;
        for(int i = 0; i < n;i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        
        int m;
        cin >> m;

        while(m--)
        {
            char op;
            cin >> op;

            int st, cnt;
            cin >> st >> cnt;

            vector<int> tmp;
            for(int i = 0; i < cnt; i++)
            {
                int x;
                cin >> x;
                tmp.push_back(x);
            }

            v.insert(v.begin() + st, tmp.begin(), tmp.end());
        }

        cout << "#" << t << " ";
        for(int i = 0; i < 10; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}