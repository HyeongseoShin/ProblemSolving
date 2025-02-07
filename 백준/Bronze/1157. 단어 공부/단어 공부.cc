// https://www.acmicpc.net/problem/1157
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    unordered_map<char, int> um;

    for(int i = 0; i < (int)s.length(); i++)
    {
        um[toupper(s[i])]++;
    }

    int maxFreq = 0;
    char maxChar = 'A';
    
    for(auto [c, frq] : um)
    {
        if(frq > maxFreq)
        {
            maxChar = c;
            maxFreq = frq;
        }
    }

    for(auto [c, frq] : um)
    {
        if(maxChar != c && frq == maxFreq)
        {
            maxChar = '?';
            break;
        }
    }

    cout << maxChar << "\n";

    return 0;
}