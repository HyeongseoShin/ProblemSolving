#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int solution(int number, int limit, int power) {
    for(int i = 1; i <= number; i++)
    {
        int cnt = 0;
        for(int j = 1; j * j <= i; j++)
        {
            if(j * j == i) cnt++;
            else if(i % j == 0) cnt += 2;
        }
        
        if(cnt > limit) ans += power;
        else ans += cnt;
    }
    
    return ans;
}