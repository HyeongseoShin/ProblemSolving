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
    
    // 가장 큰 값을 --> 정방향 진행으로 두고 시작
    int minVal = n - 1;
    
    for(int i = 0; i < n; i++)
    {
        // 알파벳 같게 만들기
        ans += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        // 이동해야 할 위치 찾기
        int idx = i + 1;
        while(name[idx] == 'A') idx++;
        
        // 정방향 vs 역방향 중 가까운 값
        int moveCnt = min(i * 2 + n - idx, i + (n - idx) * 2);
        minVal = min(minVal, moveCnt);
        
        
    }
    
    return ans + minVal;
}