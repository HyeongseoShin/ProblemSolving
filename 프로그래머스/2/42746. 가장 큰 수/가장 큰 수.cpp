#include <bits/stdc++.h>

using namespace std;

bool cmp(string A, string B)
{
    return A + B > B + A;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    
    for(auto num : numbers)
    {
        v.push_back(to_string(num));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(auto s : v)
    {
        answer += s;
    }
    
    if(answer == string(answer.length(), '0')) answer = "0";
    
    return answer;
}