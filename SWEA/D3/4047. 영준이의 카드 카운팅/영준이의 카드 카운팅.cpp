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
        unordered_set<int> S, D, H, C;

        string str;
        cin >> str;

        string tmp = "";
        bool isPossible = true;

        for(int i = 0; i < (int)str.length(); i++)
        {
            tmp += str[i];

            if(i % 3 == 2)
            {
                int num = (tmp[1] - '0') * 10 + tmp[2];

                if(tmp[0] == 'S')
                {
                    if(S.find(num) != S.end()) 
                    {
                        isPossible = false;
                        break;
                    }

                    S.insert(num);
                }

                else if(tmp[0] == 'D')
                {
                    if(D.find(num) != D.end()) 
                    {
                        isPossible = false;
                        break;
                    }

                    D.insert(num);
                }

                else if(tmp[0] == 'H')
                {
                    if(H.find(num) != H.end()) 
                    {
                        isPossible = false;
                        break;
                    }

                    H.insert(num);
                }

                else if(tmp[0] == 'C')
                {
                    if(C.find(num) != C.end()) 
                    {
                        isPossible = false;
                        break;
                    }

                    C.insert(num);
                }

                tmp = "";
            }
        }

        cout << "#" << t << " ";
        if(!isPossible) cout << "ERROR\n";
        else cout << 13 - (int) S.size() << " " << 13 - (int) D.size() << " " << 13 - (int) H.size() << " " << 13 - (int) C.size() << "\n";
        
    }
    return 0;
}