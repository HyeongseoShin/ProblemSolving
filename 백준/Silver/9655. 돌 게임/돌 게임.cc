#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    if(((n / 3) % 2 == 1 && (n % 3) % 2 == 0) || ((n / 3) % 2 == 0 && (n % 3) % 2 == 1)) cout << "SK\n";
    else cout << "CY\n";
    
    return 0;
}