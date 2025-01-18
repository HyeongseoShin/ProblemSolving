/*
브루트 포스 알고리즘 (완전 탐색)
*/
#include <bits/stdc++.h>

using namespace std;

int result[50][10];
int n;
int score = 0;
int order[9];

int GetScore()
{
    int sum = 0;
    int cur = 0;

    for(int i = 0; i < n; i++)
    {
        int out = 0;
        int base[3] = {0, 0, 0}; // 각 주자별 상황
        while(out < 3)
        {
            int curHitter = order[cur];

            if(result[i][curHitter] == 0)
            {
                out++;
                cur = (cur + 1) % 9;
                continue;
            }

            for(int j = 0; j < 3; j++)
            {
                if(base[j] != 0)
                {
                    base[j] += result[i][curHitter];

                    if(base[j] >= 4)
                    {
                        sum++;
                        base[j] = 0;
                    }
                }
            }

            for(int j = 0; j < 3; j++)
            {
                if(base[j] == 0)
                {
                    base[j] = result[i][curHitter];

                    if(base[j] >= 4)
                    {
                        sum++;
                        base[j] = 0;
                    }

                    break;
                }
            }

            cur = (cur + 1) % 9;
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> result[i][j];
        }
    }

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    do {
        int cur = 0;
		for (int i = 0; i < v.size(); i++) {
            if(cur == 3) cur++;
			order[cur++] = v[i];
		}

        order[3] = 0;

        score = max(score, GetScore());
	} while (next_permutation(v.begin(), v.end()));

    cout << score << "\n";

    return 0;
}