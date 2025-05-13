// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV14zIwqAHwCFAYD&categoryId=AV14zIwqAHwCFAYD&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=3

// vector: insert / erase 활용

// 쉬움

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
            int s;
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

                vector<int> tmp;
                while(cnt--)
                {
                    int s;
                    cin >> s;

                    tmp.push_back(s);
                }

                v.insert(v.begin() + st, tmp.begin(), tmp.end());
            }

            else if(op == 'D')
            {
                int st, cnt;
                cin >> st >> cnt;

                v.erase(v.begin() + st, v.begin() + st + cnt);                
            }

            else if(op == 'A')
            {
                int cnt;
                cin >> cnt;

                while(cnt--)
                {
                    int s;
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