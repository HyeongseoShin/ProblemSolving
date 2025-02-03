#include <bits/stdc++.h>

using namespace std;

int n;

bool check[21];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string op;
    int x;

    cin >> n;

    while(n--)
    {
        cin >> op;

        if(op == "all") fill(check, check + 21, true);
        else if(op == "empty") fill(check, check + 21, false);

        else
        {
            cin >> x;

            if(op == "add") check[x] = true;
            else if(op == "remove") check[x] = false;
            else if(op == "toggle") check[x] = !check[x];
            else if(op == "check") cout << check[x] << "\n";   
        }
    }

    return 0;
}