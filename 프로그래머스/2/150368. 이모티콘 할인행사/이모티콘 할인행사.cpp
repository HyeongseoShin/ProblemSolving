#include <bits/stdc++.h>

using namespace std;

int n, m;

// <이모티콘 플러스 회원 수, 판매액>
pair<int, int> ans;

vector<pair<int, int>> Users; // 비율, 가격

vector<int> Emoticons; // 이모티콘 가격

int discount[10]; // 순열 돌며 현재 이모티콘의 할인율
int dcRate[4] = {10, 20, 30, 40}; // 할인율 후보

void getComb()
{
    // 현재 <이모티콘 플러스 회원 수, 판매액>
    pair<int, int> cur = {0, 0};
    
    for(int i = 0; i < n; i++)
    {
        auto [curCnt, curPrice] = cur;
        auto [uRate, uPrice] = Users[i];
        
        // 현재 판매액
        int curSum = 0;
        for(int j = 0; j < m; j++)
        {
            // 이모티콘 일정 이상 할인하면 산다.
            if(discount[j] >= uRate)
            {
                curSum += ((Emoticons[j] / 100) * (100 - discount[j]));
            }
        }
        
        // 이모티콘 플러스로 전환
        if(curSum >= uPrice) cur = {curCnt+1, curPrice};
        else cur = {curCnt, curPrice + curSum};
    }
    
    ans = max(ans, cur);
}
void getAns(int idx)
{
    // 순열 끝났으면 연산 수행
    if(idx >= m)
    {
        getComb();
        return;
    }
    
    // 10 ~ 40 할인율 완전 탐색
    for(int i = 0; i < 4; i++)
    {
        discount[idx] = dcRate[i];
        getAns(idx + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    n = (int)users.size();
    m = (int)emoticons.size();
    
    // 전역으로 저장
    for(int i = 0; i < n; i++) Users.push_back({users[i][0], users[i][1]});
    for(int i = 0; i < m; i++) Emoticons.push_back(emoticons[i]);
    
    // DFS 진행 (순열)
    getAns(0);
    
    // 정답 업데이트
    auto [ansCnt, ansPrice] = ans;
    
    vector<int> answer;
    answer.push_back(ansCnt);
    answer.push_back(ansPrice);
    
    return answer;
}