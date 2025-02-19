#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, s;

int arr[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minLen = 0x7fffffff;
    int tot = arr[0];
    int en = 0;

    for(int st = 0; st < n; st++)
    {
        while(en < n && tot < s)
        {
            en++;

            if(en != n)
            {
                tot += arr[en];
            }
        }

        if(en == n)
        {
            break;
        }

        minLen = min(minLen, en - st + 1);

        tot -= arr[st];
    }

    if(minLen == 0x7fffffff)
    {
        minLen = 0;
    }

    cout << minLen << "\n";


    return 0;
}