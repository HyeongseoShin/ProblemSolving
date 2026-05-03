#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int ans = -1;
ll sum = 0, sumA = 0, sumB = 0;
queue<int> qA;
queue<int> qB;
int solution(vector<int> queue1, vector<int> queue2) {
    
    n = (int)queue1.size();
    
    for(int i = 0; i < n; i++)
    {
        sumA += queue1[i];
        qA.push(queue1[i]);
    }
    
    for(int i = 0; i < n; i++) 
    {
        sumB += queue2[i];
        qB.push(queue2[i]);
    }
    
    sum = sumA + sumB;
    
    // 홀수면 불가능
    if(sum % 2 != 0) return -1;
    
    int cnt = 0;
    while(!qA.empty() && !qB.empty())
    {
        int fA = qA.front();
        int fB = qB.front();
        
        if(sumA == sumB)
        {
            ans = cnt;
            break;
        }
        
        if(cnt > n * 4)break;
        
        else if(sumA > sumB)
        {
            sumA -= fA;
            qA.pop();
            
            sumB += fA;
            qB.push(fA);
        }
        
        else
        {
            sumB -= fB;
            qB.pop();
            
            sumA += fB;
            qA.push(fB);
        }
        
        cnt++;
    }
    
    return ans;
}