#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> cols;
vector<vector<int>> candidateKeys;

bool isUnique(vector<vector<string>> &relation)
{
    set<vector<string>> tmp;

    for(int i = 0; i < n; i++)
    {
        vector<string> row;

        for(int j = 0; j < (int)cols.size(); j++)
        {
            int cur = cols[j];
            row.push_back(relation[i][cur]);
        }

        if(tmp.find(row) != tmp.end()) return false;
        tmp.insert(row);
    }

    return true;
}

bool isMinimal()
{
    for(vector<int> key : candidateKeys)
    {
        bool isIncluded = true;

        for(int i = 0; i < (int)key.size(); i++)
        {
            int cur = key[i];

            if(find(cols.begin(), cols.end(), cur) == cols.end())
            {
                isIncluded = false;
                break;
            }
        }

        if(isIncluded) return false;
    }

    return true;
}

void dfs(int idx, int targetCnt, vector<vector<string>> &relation)
{
    if((int)cols.size() == targetCnt)
    {
        if(!isMinimal()) return;

        if(isUnique(relation))
        {
            candidateKeys.push_back(cols);
        }

        return;
    }

    for(int i = idx; i < m; i++)
    {
        cols.push_back(i);
        dfs(i + 1, targetCnt, relation);
        cols.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    n = (int)relation.size();
    m = (int)relation[0].size();

    candidateKeys.clear();
    cols.clear();

    for(int cnt = 1; cnt <= m; cnt++)
    {
        dfs(0, cnt, relation);
    }

    return (int)candidateKeys.size();
}