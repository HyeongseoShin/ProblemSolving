#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int m = (int)stations.size();
    
    int cur = 1;
    for(int i = 0; i < m; i++)
    {
        int idx = stations[i] - w - 1;
        
        if(cur <= idx)
        {
            answer += ceil((double)(idx - cur + 1) / (double)(w*2+1));
        }
            
        cur = stations[i] + w + 1;
        
    }
        
    if(cur <= n)
    {
        answer += ceil((double)(n - cur + 1) / (double)(w*2+1));
    }

    return answer;
}