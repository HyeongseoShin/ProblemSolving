// https://www.acmicpc.net/problem/2668
#include <bits/stdc++.h>

using namespace std;

int n;

int arr[200];
bool isRemoved[200];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int ans = n;
    while(true)
    {
        bool isPossible = true;
        for(int i = 1; i <= n; i++)
        {
            if(isRemoved[i]) continue;

            bool isSame = false;
            for(int j = 1; j <= n; j++)
            {
                if(!isRemoved[j] && ((i == arr[i]) || (i != j && i == arr[j])))
                {
                    isSame = true;
                    break;
                }
            }

            if(!isSame)
            {
                // cout << "i: " << i << "\n";
                isPossible = false;
                isRemoved[i] = true;
                ans--;
            }
        }

        if(isPossible) break;
    }

    // cout  << "=======\n";
    cout << ans << "\n";

    for(int i = 1; i <= n; i++)
    {
        if(!isRemoved[i]) cout << i << "\n";
    }

    return 0;
}