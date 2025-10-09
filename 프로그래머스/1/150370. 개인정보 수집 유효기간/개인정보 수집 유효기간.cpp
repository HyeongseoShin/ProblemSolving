#include <bits/stdc++.h>

using namespace std;

// 오늘 연, 월, 일
int tY = -1, tM = -1, tD = -1;

// <약관, 유효기간>
unordered_map<string, int> termInfo;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    stringstream ss(today);
    
    string token;
    
    // 오늘 연, 월, 일 구하기
    while(getline(ss, token, '.'))
    {
        if(tY == -1) tY = stoi(token);
        else if(tM == -1) tM = stoi(token);
        else if(tD == -1) tD = stoi(token);
    }
    
    // 약관 별 유효기간 구하기
    for(auto term : terms)
    {
        stringstream ss(term);
        string token;
        
        string s = "a";
        int m = -1;
        
        while(getline(ss, token, ' '))
        {
            if(s == "a") s = token;
            else if(m == -1) m = stoi(token);
        }
        
        termInfo[s] = m;
    }
    
    vector<int> ans;
    
    // 정답 구하기
    for(int i = 0; i < (int)privacies.size(); i++)
    {
        string nDate = "";
        string s;
        
        stringstream ss(privacies[i]);
        string token;
        
        // 날짜, 약관 분리
        while(getline(ss, token, ' '))
        {
            if(nDate == "") nDate = token;
            else s = token;
        }
        
        int nY = -1, nM = -1, nD = -1;
        
        stringstream ss2(nDate);

        // 오늘 연, 월, 일 구하기
        while(getline(ss2, token, '.'))
        {
            if(nY == -1) nY = stoi(token);
            else if(nM == -1) nM = stoi(token);
            else if(nD == -1) nD = stoi(token);
        }
        

        int tempM = nM;
        nY += ((nM + termInfo[s]) / 12);
        nM = (tempM + termInfo[s]) % 12;
        
        if((tempM + termInfo[s]) % 12 == 0)
        {
            // cout << "i: " << i << "\n";
            nY--;
        }
        if(nM == 0) nM = 12;
        
        nD--;
        
        if(nD == 0)
        {
            nD = 28;
            nM--;
            
            if(nM == 0)
            {
                nM = 12;
                nY--;
            }
        }
        
        // cout << tY << " " << tM << " " << tD << "\n";
        // cout << nY << " " << nM << " " << nD << " " << termInfo[s] << "\n\n";
        
        
        
        if(nY < tY) ans.push_back(i+1);
        else if(nY == tY && nM < tM) ans.push_back(i+1);
        else if(nY == tY && nM == tM && nD < tD) ans.push_back(i+1);
        
    }
    
    return ans;
}