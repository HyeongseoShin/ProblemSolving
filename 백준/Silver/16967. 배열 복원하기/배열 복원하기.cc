#include <bits/stdc++.h>

using namespace std;

int h, w, x, y;

int A[605][605];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w >> x >> y;

    for(int i = 0; i < h + x; i++)
    {
        for(int j = 0; j < w + y; j++)
        {
            cin >> A[i][j];
        }
    }
    
    for(int i = x; i < h; i++)
    {
        for(int j = y; j < w; j++)
        {
            A[i][j] -= A[i-x][j-y];
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}