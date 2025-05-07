#include <bits/stdc++.h>

using namespace std;

// dpMax[i][j] : i ~ j까지 계산했을 때 최대값
int dpMax[102][102];

// dpMin[i][j] : i ~ j까지 계산했을 때 최소값
int dpMin[102][102];

int solution(vector<string> arr)
{
    int n = ((int)arr.size() + 1) / 2;
    
    // dp 초기화
    for(int i = 0; i < 102; i++)
    {
        for(int j = 0; j < 102; j++)
        {
            dpMax[i][j] = INT_MIN;
            dpMin[i][j] = INT_MAX;
        }
    }
    
    // dp 초기값 지정 (i ~ i)까지 연산 : arr[i]
    for(int i = 0; i < n; i++)
    {
        int idx = i * 2;
        dpMax[i][i] = stoi(arr[idx]);
        dpMin[i][i] = stoi(arr[idx]);
    }
    
    for(int idx = 1; idx < n; idx++)
    {
        for(int st = 0; st < n - idx; st++)
        {
            int en = idx + st;
            for(int k = st; k < en; k++)
            {
                // cout << "st : " << st << " k : " << k << " en: " << en << "\n";
                if(arr[k * 2 + 1] == "-")
                {
                    dpMax[st][en] = max(dpMax[st][en], dpMax[st][k] - dpMin[k+1][en]);
                    dpMin[st][en] = min(dpMin[st][en], dpMin[st][k] - dpMax[k+1][en]);
                }
                else if(arr[k * 2 + 1] == "+")
                {
                    dpMax[st][en] = max(dpMax[st][en], dpMax[st][k] + dpMax[k+1][en]);
                    dpMin[st][en] = min(dpMin[st][en], dpMin[st][k] + dpMin[k+1][en]);
                }
            }
        }
    }
    
    return dpMax[0][n - 1];
    
}