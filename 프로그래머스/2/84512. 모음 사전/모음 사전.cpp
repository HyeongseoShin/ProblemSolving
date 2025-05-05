#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int cnt = 0;

string target;

char c[5] = {'A', 'E', 'I', 'O', 'U'};

void GetAns(string cur)
{
    if(ans != 0) return;
    
    if(cur == target)
    {
        ans = cnt;
        return;
    }
    
    if((int)cur.length() == 5) return;
    
    for(int i = 0; i < 5; i++)
    {
        cnt++;
        GetAns(cur + c[i]);
        
    }
}
int solution(string word) {
    target = word;
    
    GetAns("");
    
    return ans;
}