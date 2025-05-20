#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        ll n;
        cin >> n;

        int sum = 0;

        while(n > 0)
        {
            sum += (n % 10);
            n /= 10;
        }

        while((sum / 10) > 0)
        {
            int tmp = sum;

            sum = 0;
            while(tmp > 0)
            {
                sum += (tmp % 10);
                tmp /= 10;
            }
        }

        cout << "#" << t << " " << sum << "\n";
    }
    return 0;
}