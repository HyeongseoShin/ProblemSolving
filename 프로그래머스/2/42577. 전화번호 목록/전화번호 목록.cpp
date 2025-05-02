#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_set<string> us(phone_book.begin(), phone_book.end());
    
    for(auto s : phone_book)
    {
        string tmp = "";
        for(int i = 0; i < (int)s.length() - 1; i++)
        {
            tmp += s[i];
            if(us.count(tmp)) return false;
        }
    }
    return true;
}