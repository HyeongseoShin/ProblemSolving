#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

// <정점, 들어오는 개수>
unordered_map<int, int> inDegree;

// <정점, 나가는 개수>
unordered_map<int, int> outDegree;

// 새롭게 생긴 정점
int createdV = 0;

// 도넛, 막대, 8자 그래프 개수
int donutCnt = 0, barCnt = 0, eightCnt = 0;

// 정점 집합
unordered_set<int> points;


bool isBar(int u)
{
    if(inDegree[u] == 1 && outDegree[u] == 0) return true;
    else if(inDegree[u] == 0 && outDegree[u] == 0) return true;
    else return false;
}

bool isEight(int u)
{
    if(inDegree[u] == 2 && outDegree[u] == 2) return true;
    else return false;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    int n = (int)edges.size();
    
    // 새롭게 생성된 정점 구하기
    for(int i = 0; i < n; i++)
    {
        int from = edges[i][0];
        int to = edges[i][1];
        
        outDegree[from]++;
        inDegree[to]++;
        
        points.insert(from);
        points.insert(to);
    }
    
    // 새롭게 생성된 정점 : outDegree >= 2 && inDegree == 0
    for(auto [v, cnt] : outDegree)
    {
        if(cnt >= 2 && inDegree[v] == 0)
        {
            createdV = v;
            break;
        }
    }
    
    // 정점 삭제
    // outDegree[createdV]는 총 그래프 개수여서 남겨놓기
    for(int i = 0; i < n; i++)
    {
        int from = edges[i][0];
        int to = edges[i][1];
        
        if(from == createdV) inDegree[to]--;
    }
    
    
    for(auto u : points)
    {
        if(isBar(u)) barCnt++;
        else if(isEight(u)) eightCnt++;
    }
    
    donutCnt = outDegree[createdV] - barCnt - eightCnt;
    
    answer.push_back(createdV);
    answer.push_back(donutCnt);
    answer.push_back(barCnt);
    answer.push_back(eightCnt);
    
    return answer;
}