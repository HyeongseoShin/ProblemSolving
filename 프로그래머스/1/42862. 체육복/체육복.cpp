#include <bits/stdc++.h>

using namespace std;

// 1 : 여분 있음
// 0 : 체육복 있음
// -1 : 체육복 없음
int student[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i = 0; i < (int)reserve.size(); i++)
    {
        student[reserve[i]]++;    
    }
    
    for(int i = 0; i < (int)lost.size(); i++)
    {
        student[lost[i]]--;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(student[i] == -1)
        {
            if(i - 1 >= 1 && student[i-1] >= 1)
            {
                student[i-1]--;
                student[i]++;
            }
            else if(i + 1 <= n && student[i+1] >= 1)
            {
                student[i+1]--;
                student[i]++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(student[i] >= 0) answer++;
    }
    
    cout << "\n";
    return answer;
}