#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> v;

// 수 2개를 뽑아 더한 모든 경우의 수 들어가 있는 Vector
vector<int> two;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    v.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            two.push_back(v[i] + v[j]);
        }
    }

    sort(two.begin(), two.end());

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 0; j < n; j++)
        {
            if(binary_search(two.begin(), two.end(), v[i] - v[j]))
            {
                cout << v[i] << "\n";
                return 0;
            }
        }
    }

    return 0;
}