#include <bits/stdc++.h>

using namespace std;

bool cmp (string A, string B)
{
    return stoi(A+B) > stoi(B+A);
}
string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    for(int i = 0; i < (int)numbers.size(); i++)
    {
        
        v.push_back(to_string(numbers[i]));
    }
    
    sort(v.begin(), v.end(), greater<>());
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < (int)v.size(); i++)
    {
        answer += v[i];
    }
    
    if(answer[0] == '0') return "0";
    return answer;
}