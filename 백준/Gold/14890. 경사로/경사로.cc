#include <bits/stdc++.h>

using namespace std;

int boardRow[101][101];
int boardCol[101][101];

int n, l;

int ans = 0;

bool CanMakeRoad(int A[101][101], int x, int y)
{
    int len = 1;
    for(int i = y + 1; i < n; i++)
    {
        if(A[x][y] == A[x][i]) len++;
        else break;
    }

    if(len >= l) return true;
    else return false;
}
int GetAns(int A[101][101])
{
    int result = 0;

    for(int i = 0; i < n; i++)
    {
        int beforeRoad = 1; // 이때까지 온 높이가 같은 길의 길이
        bool isPossible = true;
        for(int j = 0; j < n - 1; j++)
        {
            // 높이 차 1보다 크면 아예 불가능
            if(abs(A[i][j] - A[i][j+1]) > 1)
            {
                isPossible = false;
                break;
            }

            // 높이 같은 걸어온 길 길이 업데이트
            if(A[i][j] == A[i][j+1]) beforeRoad++;

            // 오르막길 설치해야할 때
            else if(A[i][j] + 1 == A[i][j+1])
            {
                // l보다 짧으면 불가능
                if(beforeRoad < l)
                {
                    isPossible = false;
                    break;
                }

                else beforeRoad = 1;
            }

            // 내리막길 설치해야 할 때
            else if(A[i][j] == A[i][j+1] + 1)
            {
                if(CanMakeRoad(A, i, j+1))
                {
                    j = j + l - 1;
                    beforeRoad = 0;
                }

                else
                {
                    isPossible = false;
                    break;
                }
            }
        }

        if(isPossible) result++;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> boardRow[i][j];

            boardCol[j][i] = boardRow[i][j];
        }
    }

    int ans = GetAns(boardRow) + GetAns(boardCol);
    cout << ans << "\n";

    return 0;
}