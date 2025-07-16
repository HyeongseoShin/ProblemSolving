#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int>> wires;

int ans = 0;
int sz = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        wires.push_back({a, b});
    }

    sort(wires.begin(), wires.end());

    vector<int> lisVal; // LIS 값
    vector<int> lisIdx; // LIS 구성 인덱스 (역추적용)

    for(int i = 0; i < n; i++)
    {
        auto [a, b] = wires[i];
        auto idx = lower_bound(lisVal.begin(), lisVal.end(), b) - lisVal.begin();

        if(idx < (int)lisVal.size())
        {
            
            lisVal[idx] = b;
            lisIdx.push_back(idx);
        }

        else
        {
            lisVal.push_back(b);
            lisIdx.push_back((int)lisVal.size() - 1);
        }
    }
    
    sz = n - (int)lisVal.size();
    cout << sz << "\n";

    vector<int> ans;

    int now = lisVal.size() - 1;

    for(int i = lisIdx.size() - 1; i >= 0; i--)
    {
        if(now == lisIdx[i]) now--;
        else ans.push_back(wires[i].first);
    }

    sort(ans.begin(), ans.end());

    for(auto a : ans) cout << a << "\n";

    
    return 0;
}