#include <bits/stdc++.h>

using namespace std;

int answer = 0;
set<int> checks[11];

int solution(int n, vector<vector<int>> q, vector<int> ans) {

    
    for(int i = 0; i < (int)q.size(); i++)
    {
        for(int j = 0; j < 5; j++)
        {
            checks[i].insert(q[i][j]);
        }
    }
    
    vector<int> cur;
    for(int i = 1; i <= n; i++)
    {
        cur.push_back(i);
        for(int j = i + 1; j <= n; j++)
        {
            cur.push_back(j);
            for(int k = j + 1; k <= n; k++)
            {
                cur.push_back(k);
                for(int l = k + 1; l <= n; l++)
                {
                    cur.push_back(l);
                    for(int m = l + 1; m <= n; m++)
                    {
                        cur.push_back(m);
                        bool isPossible = true;
                        for(int idx = 0; idx < (int)q.size(); idx++)
                        {
                            int cnt = 0;
                            for(int num = 0; num < 5; num++)
                            {
                                if(checks[idx].find(cur[num]) != checks[idx].end())
                                {
                                    cnt++;
                                }
                            }
                            
                            if(cnt != ans[idx])
                            {
                                isPossible = false;
                                break;
                            }
                        }
                        
                        if(isPossible) answer++;
                        cur.pop_back();
                    }
                    cur.pop_back();
                }
                cur.pop_back();
            }
            cur.pop_back();
        }
        cur.pop_back();
    }
    
    cout << answer << "\n";
    
    
    return answer;
}