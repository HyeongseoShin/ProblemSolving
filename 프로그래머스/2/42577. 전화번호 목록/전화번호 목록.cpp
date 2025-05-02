#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < (int)phone_book.size() - 1; i++)
    {
        if(phone_book[i+1].substr(0, phone_book[i].length()) == phone_book[i]) return false;
    }
    
    return true;
//     unordered_set<string> us(phone_book.begin(), phone_book.end());
    
//     for(auto s : phone_book)
//     {
//         string tmp = "";
//         for(int i = 0; i < (int)s.length() - 1; i++)
//         {
//             tmp += s[i];
//             if(us.count(tmp)) return false;
//         }
//     }
//     return true;
}