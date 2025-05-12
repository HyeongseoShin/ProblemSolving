// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AV7I5fgqEogDFAXB&categoryId=AV7I5fgqEogDFAXB&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=1

#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char board[4][4];

unordered_set<string> s;

void GetAns(int x, int y, string cur, int cnt)
{
    if(cnt == 6)
    {
        s.insert(cur);
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(nX < 0 || nX >= 4 || nY < 0 || nY >= 4) continue;
        GetAns(nX, nY, cur + board[nX][nY], cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cin >> board[i][j];
            }
        }

        s.clear();
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                string tmp = "";
                tmp += board[i][j];
                GetAns(i, j, tmp, 0);
            }
        }

        cout << "#" << t << " " << (int)s.size() << "\n";
    }

    return 0;
}