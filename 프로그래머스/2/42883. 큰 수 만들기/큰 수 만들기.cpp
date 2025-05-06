#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = (int)number.length() - k;
    
    int idx = 0;
    
    // 앞에서부터 k개씩 보며 그 중 가장 큰 수 선택
    for(int i = 0; i < n; i++)
    {
        // 현재 범위에서 가장 큰 수
        int maxIdx = idx;
        
        // 이전 가장 큰 숫자 ~ (k + i) 까지 검사하며 가장 큰 수 뽑기
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