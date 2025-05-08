// 조합
#include <bits/stdc++.h>

using namespace std;

set<int> s;

bool isPrimeNum(int num)
{
    if(num < 2) return false;
    
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0) return false;
    }
    
    return true;
}


int solution(string numbers) {
    int n = (int)numbers.length();    
    vector<char> v;
    
    for(int i = 0; i < n; i++)
    {
        v.push_back(numbers[i]);
    }
    
    // 조합 사용하기 전 정렬 필요
    sort(v.begin(), v.end());
    
    do
    {
        string tmp = "";
        for(int i = 0; i < n; i++)
        {
            tmp += v[i];
            if(isPrimeNum(stoi(tmp))) s.insert(stoi(tmp));
        }
    } while(next_permutation(v.begin(), v.end()));
    
    return s.size();
}