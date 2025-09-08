#include <bits/stdc++.h>


using namespace std;

// <이름, 인덱스>
unordered_map<string, int> nameToIdx;

// 선물 주고 받은 횟수 저장
int cnt[51][51];

// 선물 지수
int score[51];

// 받을 수 있는 선물 수
int ans[51];


int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int n = (int)friends.size();
    
    // <친구 이름, 인덱스> 저장
    for(int i = 0; i < n; i++) nameToIdx[friends[i]] = i;
    
    int m = (int) gifts.size();
    
    for(int i = 0; i < m; i++)
    {
        string token;
        stringstream ss(gifts[i]);
        
        vector<string> records;
        while(getline(ss, token, ' '))
        {
            records.push_back(token);
        }
        
        string from = records[0];
        string to = records[1];
        
        int fromIdx = nameToIdx[from];
        int toIdx = nameToIdx[to];
        
        // 선물 주고 받은 횟수 업뎃
        cnt[fromIdx][toIdx]++;
        
        // 선물 지수 업뎃
        score[fromIdx]++;
        score[toIdx]--;
    }
    
    // 선물 준 사람
    for(int i = 0; i < n - 1; i++)
    {
        int from = i;
        
        // 선물 받은 사람
        for(int j = i+1; j < n; j++)
        {
            if(i == j) continue;
            
            int to = j;
            
            // 선물 주고 받은 기록 있다면 더 많이 준 사람이 선물 받기
            if(cnt[from][to] > cnt[to][from]) ans[from]++;
            else if(cnt[from][to] < cnt[to][from]) ans[to]++;
            
            // 선물 기록 없거나 주고 받은 횟수 같다면 선물지수 더 큰 사람이 받기
            else if(score[from] > score[to]) ans[from]++;
            else if(score[from] < score[to]) ans[to]++;
        }
    }
    
    sort(ans, ans + n);
    
    return ans[n-1];
}