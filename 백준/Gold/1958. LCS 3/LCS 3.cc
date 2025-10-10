#include <bits/stdc++.h>

using namespace std;

string s1, s2, s3;
int n1, n2, n3;

int lcs[101][101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2 >> s3;

    n1 = (int)s1.length();
    n2 = (int)s2.length();
    n3 = (int)s3.length();

    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            for(int k = 1; k <= n3; k++)
            {
                if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1] && s1[i-1] == s3[k-1])
                {
                    lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
                }

                else lcs[i][j][k] = max({lcs[i-1][j][k], lcs[i][j-1][k], lcs[i][j][k-1]});
            }
        }
    }

    cout << lcs[n1][n2][n3] << "\n";

    return 0;
}