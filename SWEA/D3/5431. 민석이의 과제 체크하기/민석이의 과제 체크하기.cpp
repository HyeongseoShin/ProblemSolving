#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n, k;
        cin >> n >> k;

        bool student[101];
        fill(student, student + n + 1, false);

        for(int i = 0; i < k; i++)
        {
            int x;
            cin >> x;

            student[x] = true;
        }

        cout << "#" << t << " ";
        for(int i = 1; i <= n; i++)
        {
            if(!student[i]) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;

}