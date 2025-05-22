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
        int n;
        cin >> n;

        int score[101];
        
        for(int i = 0; i < n; i++)
        {
            cin >> score[i];
        }

        bool isUsed[10001];
        fill(isUsed, isUsed + 10001, false);

        vector<int> possible;
        possible.push_back(0);
        isUsed[0] = true;

        for(int i = 0; i < n; i++)
        {
            int m = (int)possible.size();
            for(int j = m - 1; j >= 0; j--)
            {
                int check = score[i] + possible[j];
                if(!isUsed[check])
                {
                    isUsed[check] = true;
                    possible.push_back(check);
                }
            }
        }

        cout << "#" << t << " " << (int)possible.size() << "\n";
    }
    return 0;
}