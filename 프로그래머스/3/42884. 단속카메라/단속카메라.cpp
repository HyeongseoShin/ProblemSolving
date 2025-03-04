// 그리디
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 도착 지점 오름차순 정렬 (같으면 출발 지점 오름차순 정렬)
bool cmp(vector<int> A, vector<int> B)
{
    if(A[1] != B[1]) return A[1] < B[1];
    return A[0] < B[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int n = routes.size();
    
    sort(routes.begin(), routes.end(), cmp);
    
    vector<int> camPos;
    camPos.push_back(routes[0][1]);
    
    for(int i = 1; i < n; i++)
    {
        bool isPossible = true;
        for(int j = camPos.size() - 1; j >= 0; j--)
        {
            if(routes[i][0] <= camPos[j] && camPos[j] <= routes[i][1])
            {
                isPossible = false;
                break;
            }
        }
        
        if(isPossible) camPos.push_back(routes[i][1]);
    }
    
    answer = camPos.size();
    return answer;
}