#include <bits/stdc++.h>

using namespace std;

int tc, n, m;

int ranking[501]; // ranking[i] : 작년에 i 순위 차지한 팀의 번호

int num[501]; // 해당 팀의 작년 순위
int inDegree[501];

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
            inDegree[ranking[i]] = i - 1;
        }

        cin >> m;

        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;

            if(num[x] < num[y])
            {
                inDegree[x]++;
                inDegree[y]--;
            }

            else
            {
                inDegree[x]--;
                inDegree[y]++;
            }
        }

        set<int> inDegreeSet;

        // <inDegree, 팀번호>
        vector<pair<int, int>> v;
        bool isPossible = true;

        for(int i = 1; i <= n; i++)
        {
            int cur = ranking[i];

            if(inDegreeSet.count(inDegree[cur]) > 0)
            {
                isPossible = false;
                break;
            }

            v.push_back({inDegree[cur], cur});
            inDegreeSet.insert(inDegree[cur]);
        }

        if(!isPossible)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < (int)v.size(); i++)
        {
            auto [out, cur] = v[i];
            cout << cur << " ";
        }
        cout << "\n";
    }

    return 0;
}