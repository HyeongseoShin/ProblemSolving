#include <iostream>
#include <vector>

using namespace std;

string s1;
string s2;

int ans[1001][1001] = {0};
vector<char> str;

void GetText(int r, int c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;

    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i-1] == s2[j-1]) {
                ans[i][j] = ans[i-1][j-1] + 1;
            }
            else {
                ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
            }
        }
    }

    cout << ans[s1.size()][s2.size()] << "\n";

    GetText(s1.size(), s2.size());

    for(int i = str.size() - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << "\n";

    return 0;
}

void GetText(int r, int c) {
    if(r == 0 || c == 0) {
        return ;
    }
    
    if(s1[r-1] == s2[c-1]) {
        str.push_back(s1[r-1]);
        GetText(r-1, c-1);
    }

    else {
        if(ans[r-1][c] > ans[r][c-1]) {
            GetText(r-1, c);
        }
        else {
            GetText(r, c-1);
        }

    }
}