// 백트래킹 DFS
#include <bits/stdc++.h>

using namespace std;


bool vis[51];
int ans = INT_MAX;
int n;

bool CanChange(string cur, string target)
{
    int cnt = 0;
    for(int i = 0; i < cur.length(); i++)
    {
        if(cur[i] != target[i]) cnt++;
        if(cnt > 1) return false;
    }
    
    return true;
}

void GetAns(string cur, string target, vector<string> words, int cnt)
{
    if(cur == target)
    {
        ans = min(ans, cnt);
        return;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        if(!CanChange(cur, words[i])) continue;
        
        vis[i] = true;
        GetAns(words[i], target, words, cnt+1);
        vis[i] = false;
    }
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    n = (int)words.size();
    
    GetAns(begin, target, words, 0);
    
    answer = ans;
    
    if(answer == INT_MAX) return 0;
    
    return answer;
}