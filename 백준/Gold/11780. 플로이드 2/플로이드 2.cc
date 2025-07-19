#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int dst[105][105];
int nxt[105][105];

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        fill(dst[i], dst[i] + 1 + n, INF);
        dst[i][i] = 0;
    }

    while(m--)
    {
        int a, b, c;

        cin >> a >> b >> c;

        if(dst[a][b] > c)
        {
            dst[a][b] = c;
            nxt[a][b] = b;
        }
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dst[i][j] > dst[i][k] + dst[k][j])
                {
                    dst[i][j] = dst[i][k] + dst[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dst[i][j] == INF)
            {
                cout << "0 ";
            }
            else
            {
                cout << dst[i][j] << " ";
            }
        }
        cout << "\n";
    }

    // 경로 복원
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dst[i][j] == 0 || dst[i][j] == INF)
            {
                cout << "0\n";
            }

            else
            {
                // queue로 하면 메모리 초과 발생!
                // pop을 너무 많이 해서?
                vector<int> v;
                v.push_back(i);

                int nextPos = nxt[i][j];

                while(nextPos != j)
                {
                    v.push_back(nextPos);

                    nextPos = nxt[nextPos][j];
                }

                v.push_back(nextPos);

                cout << v.size() << " ";

                for(auto x: v)
                {
                    cout << x << " ";
                }
                cout << "\n";
            }   
        }
    }

    return 0;
}