#include <bits/stdc++.h>

using namespace std;

int n;

vector<string> answer;

vector<vector<string>> v;

bool vis[100001];

bool isFinished = false;
void DFS(string cur, int cnt)
{
    answer.push_back(cur);
    
    if(cnt == n)
    {
        isFinished = true;
        return;
    }
    
    for(int i = 0; i < n; i++)
    {
        string from = v[i][0];
        string to = v[i][1];
        
        if(from != cur) continue;
        if(vis[i]) continue;
        
        vis[i] = true;
        DFS(to, cnt + 1);
        
        if(!isFinished)
        {
            answer.pop_back();
            vis[i] = false;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    n = (int)tickets.size();
    sort(tickets.begin(), tickets.end());
    v = tickets;

    DFS("ICN", 0);
    
    return answer;
}