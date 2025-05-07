#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int n;
int targetNum;
vector<int> v;

void DFS(int cur, int idx)
{
    if(idx == n)
    {
        if(cur == targetNum) ans++;
        return;
    }
    
    DFS(cur + v[idx], idx + 1);
    DFS(cur - v[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    n = (int)numbers.size();
    targetNum = target;
    
    v = numbers;
    
    DFS(0, 0);
    return ans;
}