#include <bits/stdc++.h>

using namespace std;

int A[5] = {1, 2, 3, 4, 5};
int B[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int C[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
        
    int n = (int)answers.size();
    
    vector<int> v;
    
    v.resize(3);
    
    for(int i = 0; i < n; i++)
    {
        if(answers[i] == A[i % 5]) v[0]++;
        if(answers[i] == B[i % 8]) v[1]++;
        if(answers[i] == C[i % 10]) v[2]++;
    }
    
    int maxVal = *max_element(v.begin(), v.end());
    
    for(int i = 0; i < 3; i++)
    {
        if(maxVal == v[i]) answer.push_back(i+1);
    }
    return answer;
}