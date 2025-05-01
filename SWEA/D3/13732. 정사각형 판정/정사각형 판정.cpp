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
        
        char board[21][21];
        
        int cnt = 0;
        pair<int, int> st;
        
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            
            for(int j = 0; j < n; j++)
            {
				board[i][j] = s[j];
                if(board[i][j] == '#')
                {
                    if(cnt == 0) st = {i, j};
                    cnt++;
                }
            }
        }

        bool isPossible = false;
        
        int tmp = 1;
        while(tmp <= 20)
        {
			if(tmp * tmp == cnt)
            {
                isPossible = true;
                break;
            }
            tmp++;
        }
        
        if(!isPossible)
        {
            cout << "#" << t << " no\n";
            continue;
        }
        
        int sz = sqrt(cnt);
        isPossible = true;

        for(int i = st.first; i < st.first + sz; i++)
        {
            for(int j = st.second; j < st.second + sz; j++)
            {
                if(board[i][j] == '.')
                {
                    isPossible = false;
                    break;
                }
            }
			
			if(!isPossible) break;
        }
        
        cout << "#" << t << " ";
        if(isPossible) cout << "yes\n";
        else cout << "no\n";
        
    }
    return 0;
}