#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int ans = 0;
    int n = (int)name.length();
    
    string tmp;
    
    for(int i = 0; i < n; i++)
    {
        tmp += "A";
    }
    
    int minVal = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        // 알파벳 같게 만들기
        ans += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        // 이동해야 할 위치 찾기
        int idx = i + 1;
        while(name[idx] == 'A') idx++;
        
        // 
        int moveCnt = min(i * 2 + n - idx, i + (n - idx) * 2);
        minVal = min(minVal, moveCnt);
        
        
    }
    
    return ans + minVal;
}