#include <bits/stdc++.h>

using namespace std;

bool isPossible = true;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++)
    {
        int n, m;
        cin >> n >> m;
        
        int board[6][6];
        
        for(int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            
            for(int j = 1; j <= m; j++)
            {
                board[i][j] = s[j - 1] - '0';
            }
        }
        
        int A[6];
        int B[6];
        
        fill(A, A + 6, -1);
        fill(B, B + 6, -1);
        
		isPossible = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(A[i] == -1 && B[j] == -1)
                {
                    A[i] = 0;
                    
                    if(board[i][j] == 0) B[j] = 0;
                    else B[j] = 1;
                }
                
                else if(B[j] == -1)
                {
                    if(board[i][j] == 0) B[j] = A[i];
                    else B[j] = (1 - A[i]);
                }
                
                else if(A[i] == -1)
                {
                    if(board[i][j] == 0) A[i] = B[j];
                    else A[i] = (1 - B[j]);
                }
                
                else
                {

                    if((A[i] != B[j] && board[i][j] == 0) || (A[i] == B[j] && board[i][j] == 1))
                    {
                        // cout << "i: " << i << " j: " << j << " A[i]: " << A[i] << " B[j]: " << B[j] << " board[i][j] : " << board[i][j] << "\n";
                        isPossible = false;
                        break;
                    }
                }
                
                /*
                cout << "\nA: ";
                for(int k = 1; k <= n; k++) cout << A[k] << " ";
                cout << "\n";
                
                cout << "B: ";
                for(int k = 1; k <= m; k++) cout << B[k] << " ";
                cout << "\n";
                */
            }
            
            if(!isPossible) break;
        }
        
        cout << "#" << t << " ";
        if(!isPossible) cout << "no\n";
	    else cout << "yes\n";
        
        
    }
    
    
    return 0;
}