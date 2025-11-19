#include <bits/stdc++.h>

using namespace std;

int tc, n, m;

int ranking[501]; // ranking[i] : 작년에 i 순위 차지한 팀의 번호

int num[501]; // 해당 팀의 작년 순위
int inDegree[501];
int outDegree[501];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;

    while(tc--)
    {
        cin >> n;

        for(int i = 1; i <= n; i++)
        {
            cin >> ranking[i];

            num[ranking[i]] = i;
            outDegree[ranking[i]] = n - i;
            inDegree[ranking[i]] = (n - 1) - outDegree[ranking[i]];
        }

        cin >> m;

        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;

            if(num[x] < num[y])
            {
                outDegree[x]--;
                inDegree[x]++;

                outDegree[y]++;
                inDegree[y]--;
            }

            else
            {
                outDegree[x]++;
                inDegree[x]--;

                outDegree[y]--;
                inDegree[y]++;
            }
        }

        set<int> outSet;

        // <outDegree, 팀번호>
        vector<pair<int, int>> v;
        bool isPossible = true;
        for(int i = 1; i <= n; i++)
        {
            int cur = ranking[i];

            if(outSet.count(outDegree[cur]) > 0)
            {
                isPossible = false;
                break;
            }

            v.push_back({outDegree[cur], cur});
            outSet.insert(outDegree[cur]);
        }

        if(!isPossible)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        sort(v.begin(), v.end(), greater<>());

        for(int i = 0; i < (int)v.size(); i++)
        {
            auto [out, cur] = v[i];
            cout << cur << " ";
        }
        cout << "\n";
    }

    return 0;
}