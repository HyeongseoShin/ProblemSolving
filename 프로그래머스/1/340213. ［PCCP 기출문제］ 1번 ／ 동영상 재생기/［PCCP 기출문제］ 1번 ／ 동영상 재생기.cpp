#include <bits/stdc++.h>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string ans = "";
    int n = (int)commands.size();
    
    video_len.erase(2, 1);
    pos.erase(2, 1);
    op_start.erase(2, 1);
    op_end.erase(2, 1);
    
    pair<int, int> nLen = {stoi(video_len) / 100, stoi(video_len) % 100};
    pair<int, int> nPos = {stoi(pos) / 100, stoi(pos) % 100};
    pair<int, int> nOpSt = {stoi(op_start) / 100, stoi(op_start) % 100};
    pair<int, int> nOpEn = {stoi(op_end) / 100, stoi(op_end) % 100};
    
    auto [maxH, maxM] = nLen;
    auto [stH, stM] = nOpSt;
    auto [enH, enM] = nOpEn;
    
    for(int i = 0; i < n; i++)
    {
        int curPos = nPos.first * 100 + nPos.second;
        
        // 현재 오프닝 구간이면 오프닝 건너뛰기
        if(stoi(op_start) <= curPos && curPos <= stoi(op_end))
        {
            nPos = {enH, enM};
        }
        
        string command = commands[i];
        auto [curH, curM] = nPos;
        
        if(command == "prev")
        {
            curM -= 10;
            if(curM < 0)
            {
                curM+= 60;
                curH--;
            }
            
            nPos = {curH, curM};
            
            if(curH < 0) nPos = {0, 0}; 
        }
        
        else
        {
            curM += 10;
            if(curM >= 60)
            {
                curM -= 60;
                curH++;
            }
            
            nPos = {curH, curM};
            
            if(curH > maxH || (curH == maxH && curM > maxM)) nPos = {maxH, maxM};
        }
        
        // cout << "curH: " << nPos.first << " curM: " << nPos.second << "\n";
    }
    
    int curPos = nPos.first * 100 + nPos.second;
        
    // 현재 오프닝 구간이면 오프닝 건너뛰기
    if(stoi(op_start) <= curPos && curPos <= stoi(op_end))
    {
        nPos = {enH, enM};
    }
    
    if(nPos.first < 10) ans += '0';
    ans += to_string(nPos.first);
    ans += ':';
    if(nPos.second < 10) ans += '0';
    ans += to_string(nPos.second);
    
    
    return ans;
}