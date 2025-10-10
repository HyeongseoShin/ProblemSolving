// 완전 탐색

#include <bits/stdc++.h>

using namespace std;

int n, m;

int percentage[4] = {40, 30, 20, 10};

int maxPerson = -1;
int maxMoney = -1;

vector<vector<int>> customers;
vector<int> emo;

void getMaxPersonAndMoney(vector<vector<int>> users, vector<int> emoticons, vector<int> discount)
{
    int curPerson = 0;
    int curMoney = 0;
    
    for(int i = 0; i < n; i++)
    {
        int limitPercentage = users[i][0];
        int limitMoney = users[i][1];
        
        int tmpMoney = 0;
        for(int j = 0; j < m; j++)
        {
            if(discount[j] < limitPercentage) continue;
            
            tmpMoney += (emoticons[j] * (100 - discount[j])) / 100;
        }
        
        if(tmpMoney >= limitMoney) curPerson++;
        else curMoney += tmpMoney;
    }
    
    if(maxPerson < curPerson
      || maxPerson == curPerson && maxMoney < curMoney)
    {
        maxPerson = curPerson;
        maxMoney = curMoney;
    }
}
void getAns(int cur, vector<vector<int>> users, vector<int> emoticons, vector<int> discount)
{
    if(cur == m)
    {
        getMaxPersonAndMoney(users, emoticons, discount);
        // for(int i = 0; i < m; i++)
        // {
        //     cout << disCount[i] << " ";
        // }
        // cout << "\n";
        return;
    }
    
    for(int i = cur; i < m; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            discount[i] = percentage[j];
            getAns(i+1, users, emoticons, discount);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> ans;
    
    n = (int)users.size();
    m = (int)emoticons.size();
    
    vector<int> discount; // 각 이모티콘별 할인율
    discount.resize(m, 0);
    
    getAns(0, users, emoticons, discount);
    
    // cout << maxPerson << " " << maxMoney << "\n";
    ans.push_back(maxPerson);
    ans.push_back(maxMoney);
    
    return ans;
}