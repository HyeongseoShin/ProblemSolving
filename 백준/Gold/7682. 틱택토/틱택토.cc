// https://www.acmicpc.net/problem/7682

// 빡구현
#include <bits/stdc++.h>

using namespace std;

char board[9];

int xCnt = 0;
int oCnt = 0;

char GetWinner()
{
    unordered_map<char, int> um;

    if(board[0] == board[1] && board[1] == board[2] && board[0] == board[2] && board[0] != '.') um[board[0]]++;
    if(board[3] == board[4] && board[4] == board[5] && board[3] == board[5] && board[3] != '.') um[board[3]]++;
    if(board[6] == board[7] && board[7] == board[8] && board[6] == board[8] && board[6] != '.') um[board[6]]++;

    if(board[0] == board[3] && board[3] == board[6] && board[0] == board[6] && board[0] != '.') um[board[0]]++;
    if(board[1] == board[4] && board[4] == board[7] && board[1] == board[7] && board[1] != '.') um[board[1]]++;
    if(board[2] == board[5] && board[5] == board[8] && board[2] == board[8] && board[2] != '.') um[board[2]]++;

    if(board[0] == board[4] && board[4] == board[8] && board[0] == board[8] && board[0] != '.') um[board[0]]++;
    if(board[2] == board[4] && board[4] == board[6] && board[2] == board[6] && board[2] != '.') um[board[2]]++;

    char winner = '.';
    for(auto [x, frq] : um)
    {
        if(frq == 1)
        {
            if(winner == '.') winner = x;
            else winner = '*';
        }
    }

    return winner;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        string s;
        cin >> s;

        if(s == "end") break;

        xCnt = 0;
        oCnt = 0;
        
        for(int i = 0; i < 9; i++)
        {
            board[i] = s[i];
            if(s[i] == 'X') xCnt++;
            else if(s[i] == 'O') oCnt++;
        }

        // if(xCnt < oCnt || xCnt - oCnt > 1)
        // {
        //     cout << "invalid\n";
        //     continue;
        // }

        char result = GetWinner();

        // cout << "result: " << result << " xCnt: " << xCnt << " oCnt: " << oCnt << "\n";

        if((result == 'X' && xCnt - oCnt == 1)
        || (result == 'O' && xCnt == oCnt)
        || (result == '.' && xCnt == 5 && oCnt == 4))
        {
            cout << "valid\n";
        }

        else cout << "invalid\n";
    }

    return 0;
}