#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        bool cards[19];
        fill(cards, cards + 19, false);

        int p1[9];
        for(int i = 0; i < 9; i++)
        {
            cin >> p1[i];
            cards[p1[i]] = true;
        }

        int p2[9];
        int idx = 0;
        for(int i = 1; i <= 18; i++)
        {
            if(!cards[i]) p2[idx++] = i;
        }

        int p1Win = 0;
        int p2Win = 0;

        do
        {
            int p1Score = 0;
            int p2Score = 0;

            for(int i = 0; i < 9; i++)
            {
                if(p1[i] > p2[i]) p1Score += (p1[i] + p2[i]);
                else p2Score += (p1[i] + p2[i]);
            }

            if(p1Score > p2Score) p1Win++;
            else if(p1Score < p2Score) p2Win++;

        } while(next_permutation(p2, p2 + 9));

        cout << "#" << t << " " << p1Win << " " << p2Win << "\n";
    }


    return 0;
}