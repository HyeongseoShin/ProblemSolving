// https://www.acmicpc.net/problem/25757
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p, ans = 0;
    string game;

    cin >> n >> game;

    unordered_set<string> us;

    while(n--)
    {
        string s;

        cin >> s;

        us.insert(s);
    }

    if(game == "Y") p = 1;
    else if(game == "F") p = 2;
    else if(game == "O") p = 3;

    cout << us.size() / p << "\n";

    return 0;
}