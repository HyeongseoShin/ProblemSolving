#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<pair<int, int>> v; // <시작, 종료>
    vector<int> roomEndTime; // 각 방의 종료 시각
    
    
    for(int i = 0; i < (int)book_time.size(); i++)
    {
        int st = stoi(book_time[i][0].substr(0,2) + book_time[i][0].substr(3, 5));
        int en = stoi(book_time[i][1].substr(0,2) + book_time[i][1].substr(3, 5));
        
        if((en + 10) % 100 >= 60) en += 50;
        else en += 10;
        
        v.push_back({st, en});
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < (int)v.size(); i++)
    {
        if(roomEndTime.empty())
        {
            roomEndTime.push_back(v[i].second);
            continue;
        }
        
        bool isPossible = false;
        
        for(int j = 0; j < (int)roomEndTime.size(); j++)
        {
            if(roomEndTime[j] <= v[i].first)
            {
                roomEndTime[j] = v[i].second;
                isPossible = true;
                break;
            }
        }
        
        if(!isPossible)
        {
            roomEndTime.push_back(v[i].second);
        }
        
    }
    
    answer = (int)roomEndTime.size();
    
    return answer;
}