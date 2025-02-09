// https://www.acmicpc.net/problem/7568
#include <bits/stdc++.h>

using namespace std;

int n;

int arr[100][2];
vector<int> ans;
int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 0; i < n; i++)
    {
        int rank = 0;
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) rank++;
        }

        ans.push_back(rank + 1);
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << "\n";

    return 0;
}