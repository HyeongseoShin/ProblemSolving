#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int n;
vector<int> v;
int good = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        int l = 0;
        int r = n - 1;

        if(l == i) l++;
        if(r == i) r--;

        while(l < r && l < n && r >= 0)
        {
            int sum = v[l] + v[r];
            if(v[i] < sum) r--;         
            else if(v[i] > sum) l++;
            else
            {
                // cout << "v[i]: " << v[i] << " v[l]: " << v[l] << " v[r]: " << v[r] << "\n";
                good++;
                break;
            }

            if(l == i) l++;
            if(r == i) r--;
        }
    }

    cout << good << "\n";

    return 0;
    
}