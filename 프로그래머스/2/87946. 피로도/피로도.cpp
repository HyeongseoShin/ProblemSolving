#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

int n;
int ans;

bool vis[10];

// <현재 피로도, 거쳐온 던전 개수>
void GetAns(int curStamina, int cnt)
{
    ans = max(ans, cnt);
    
    for(int i = 0; i < n; i++)
    {
        auto [minStamina, useStamina] = v[i];
        
        if(!vis[i] && curStamina >= minStamina && curStamina - useStamina >= 0)
        {
            vis[i] = true;
            GetAns(curStamina - useStamina, cnt + 1);
            vis[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    n = (int)dungeons.size();
    
    for(int i = 0; i < n; i++)
    {
        v.push_back({dungeons[i][0], dungeons[i][1]});
    }
    
    GetAns(k, 0);
    
    return ans;
}