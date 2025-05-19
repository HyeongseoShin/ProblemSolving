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
        string s;
        cin >> s;

        int n = (int)s.length();

        int num = stoi(s.substr(0, 3));

        int tmp = num;

        if(tmp % 10 < 5) tmp -= (tmp % 10);
        else tmp += (10 - tmp % 10);

        string strNum = to_string(num);
        string strTmp = to_string(tmp);

        int cnt = 0;
        if((int)strNum.length() != (int)strTmp.length())
        {
            cnt = (int)strTmp.length() - (int)strNum.length();
        }

        cout << "#" << t << " " << strTmp[0] << "." << strTmp[1] << "*10^" << (n - 1 + cnt) << "\n";
    }

    return 0;
}
