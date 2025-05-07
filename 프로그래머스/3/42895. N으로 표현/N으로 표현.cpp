#include <bits/stdc++.h>

using namespace std;

// dp[i] : i개 N을 사용해 만들 수 있는 수들의 집합
// N 8개보다 많이 사용하면 -1 리턴하므로 8까지 범위 지정
unordered_set<int> dp[8];

int solution(int N, int number) {
    int answer = -1;
    
    // N, NN, NNN, ...
    int sum = 0;
    for(int i = 0; i < 8; i++)
    {
        sum = sum * 10 + N;
        dp[i].insert(sum);
    }
    
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < i; j++)
        {
            for(auto a : dp[j])
            {
                for(auto b : dp[i - j - 1])
                {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    
                    if(b != 0) dp[i].insert(a / b);
                }
            }
        }
    }
    
    for(int i = 0; i < 8; i++)
    {
        if(dp[i].count(number))
        {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}