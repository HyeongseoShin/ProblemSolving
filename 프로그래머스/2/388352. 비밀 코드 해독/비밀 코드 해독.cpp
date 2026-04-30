#include <bits/stdc++.h>

using namespace std;

int answer = 0;

vector<int> curNums;

bool checkPossible(vector<vector<int>> &q, vector<int> &ans)
{
    for(int i = 0; i < (int)q.size(); i++)
    {
        int cnt = 0;
        for(int j = 0; j < (int)curNums.size(); j++)
        {
            if(find(q[i].begin(), q[i].end(), curNums[j]) != q[i].end()) cnt++;
        }
        
        if(ans[i] != cnt) return false;
    }
    
    return true;
}

void dfs(int cur, int n, vector<vector<int>> &q, vector<int> &ans)
{
    if((int)curNums.size() == 5)
    {
        if(checkPossible(q, ans)) answer++;
        return;
    }
    
    for(int i = cur; i <= n; i++)
    {
        curNums.push_back(i);
        dfs(i + 1, n, q, ans);
        curNums.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    dfs(1, n, q, ans);
    
    return answer;
}