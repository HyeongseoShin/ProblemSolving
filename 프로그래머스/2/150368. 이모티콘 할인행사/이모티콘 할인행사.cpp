#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ans;

// <이모티콘 플러스, 판매액>
pair<int, int> comb;

// 비율, 가격
vector<pair<int, int>> Users;
vector<int> Emoticons;

int rate[10];
int percent[4] = {10, 20, 30, 40};

void getComb()
{
    pair<int, int> cur = {0, 0};
    for(int i = 0; i < n; i++)
    {
        auto [curCnt, curP] = cur;
        auto [curRate, curPrice] = Users[i];
        int curSum = 0;
        for(int j = 0; j < m; j++)
        {
            // 이모티콘 일정 이상 할인하면 산다.
            if(rate[j] >= curRate)
            {
                curSum += ((Emoticons[j] / 100) * (100 - rate[j]));
            }
        }
        
        // 이모티콘 플러스로 전환
        if(curSum >= curPrice) cur = {curCnt+1, curP};
        else cur = {curCnt, curP + curSum};
    }
    
    comb = max(comb, cur);
}
void getAns(int idx)
{
    if(idx >= m)
    {
        getComb();
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        rate[idx] = percent[i];
        getAns(idx + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    n = (int)users.size();
    m = (int)emoticons.size();
    
    for(int i = 0; i < n; i++) Users.push_back({users[i][0], users[i][1]});
    for(int i = 0; i < m; i++) Emoticons.push_back(emoticons[i]);
    
    getAns(0);
    
    auto [ansCnt, ansP] = comb;
    
    ans.push_back(ansCnt);
    ans.push_back(ansP);
    
    
    return ans;
}