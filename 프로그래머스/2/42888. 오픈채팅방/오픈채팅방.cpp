#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> nickname;
    
    vector<pair<string, string>> v;
    for(auto r : record)
    {
        stringstream ss(r);
        string token;
        
        vector<string> cur;
        while(getline(ss, token, ' ')) cur.push_back(token);
        
        if(cur[0] == "Enter")
        {
            nickname[cur[1]] = cur[2];
            v.push_back({cur[1], "님이 들어왔습니다."});
        }
        
        else if(cur[0] == "Leave")
        {
            v.push_back({cur[1], "님이 나갔습니다."});
        }
        
        if(cur[0] == "Change")
        {
            nickname[cur[1]] = cur[2];
        }    
    }
    
    for(auto [uid, msg] : v)
    {
        answer.push_back(nickname[uid] + msg);
    }
    
    return answer;
}