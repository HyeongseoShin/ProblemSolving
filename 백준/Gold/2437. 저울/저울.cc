#include <bits/stdc++.h>

using namespace std;

vector<int> weights;
int n;

int ans = 1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        weights.push_back(x);
    }

    sort(weights.begin(), weights.end());

    for(int i = 0; i < n; i++)
    {
        if(weights[i] <= ans) ans += weights[i];
        else break;
    }

    cout << ans << "\n";


    return 0;
}