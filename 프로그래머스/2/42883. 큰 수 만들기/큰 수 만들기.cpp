#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = (int)number.length() - k;
    
    int idx = 0;
    // 앞에서부터 k개씩 보며 그 중 가장 큰 수 선택
    for(int i = 0; i < n; i++)
    {
        int maxIdx = idx;
        
        for(int j = idx; j <= k + i; j++)
        {
            if(number[maxIdx] < number[j])
            {
                maxIdx = j;
            }
        }
        
        answer += number[maxIdx];
        idx = maxIdx + 1;
    }
    return answer;
}