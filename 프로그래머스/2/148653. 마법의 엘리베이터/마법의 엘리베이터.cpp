/*
floating signal ==> 수를 0으로 나눌 때 문제 생김

*/
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0)
    {
        // 그냥 / 10만 하면 됨 자릿수가 날라가서
        // 왜 storey - storey % 10 이런 걸 했었을까
        int cur = storey % 10;
        
        // 현재 수가 5이고 5이상의 수가 연속적일 때
        if(cur > 5 || (cur == 5 && storey / 10 % 10 >= 5))
        {
            answer += 10 - cur;
            storey += cur;
        }
        
        else
        {
            answer += cur;
            storey -= cur;
        }
        
        // 그냥 / 10만 하면 됨 자릿수가 날라가서
        // 왜 storey - storey % 10 이런 걸 했었을까
        storey /= 10;
    }
    
    return answer;
}