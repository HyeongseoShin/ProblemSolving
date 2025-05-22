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
        int board[5][5];

        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for(int j = 0; j < m; j++)
            {
                board[i][j] = s[j] - '0';
            }
        }

        bool isPossible = true;

        vector<int> A(n, -1);
        A[0] = 0;

        vector<int> B(m, -1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 0)
                {
                    if(A[i] == -1) A[i] = B[j];
                    else if(B[j] == -1) B[j] = A[i];

                    if(A[i] != B[j])
                    {
                        isPossible = false;
                        break;
                    }
                }

                else
                {
                    if(A[i] == -1) A[i] = 1 - B[j];
                    else if(B[j] == -1) B[j] = 1 - A[i];

                    if(A[i] == B[j])
                    {
                        isPossible = false;
                        break;
                    }
                }
            }

            if(!isPossible) break;
        }

        cout << "#" << t << " ";
        if(isPossible) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}