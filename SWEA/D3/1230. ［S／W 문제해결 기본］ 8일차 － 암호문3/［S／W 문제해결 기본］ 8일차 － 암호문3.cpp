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

        vector<string> v;

        for(int i = 0; i < n;i++)
        {
            string s;
            cin >> s;

            v.push_back(s);
        }

        int m;
        cin >> m;

        while(m--)
        {
            char op;
            cin >> op;

            
            if(op == 'I')
            {
                int st, cnt;
                cin >> st >> cnt;

                vector<string> tmp;
                while(cnt--)
                {
                    string s;
                    cin >> s;

                    tmp.push_back(s);
                }

                v.insert(v.begin() + st, tmp.begin(), tmp.end());
            }

            else if(op == 'D')
            {
                int st, cnt;
                cin >> st >> cnt;

                while(cnt--)
                {
                    v.erase(v.begin() + st);
                }
                
            }

            else if(op == 'A')
            {
                int cnt;
                cin >> cnt;

                while(cnt--)
                {
                    string s;
                    cin >> s;

                    v.push_back(s);
                }
            }
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