#include <bits/stdc++.h>

using namespace std;

int m, n;

int bug[2000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    fill(bug, bug + 2000, 1);

    while(n--)
    {
        int cnt[3];

        int zero, one, two;
        cin >> zero >> one >> two;

        for(int i = zero; i < zero + one; i++)
        {
            bug[i] += 1;
        }

        for(int i = zero + one; i < zero + one + two; i++)
        {
            bug[i] += 2;
        }
    }

    for(int i = 0; i < m; i++)
    {
        cout << bug[m - i - 1] << " ";
        
        for(int j = 1; j < m; j++)
        {
            cout << bug[m + j - 1] << " ";
        }
        cout << "\n";
    }

    return 0;
}