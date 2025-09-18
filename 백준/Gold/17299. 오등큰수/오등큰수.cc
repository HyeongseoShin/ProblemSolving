#include <bits/stdc++.h>

using namespace std;

int n;

int nums[1000001];

int freq[1000001];

vector<int> ans;

stack<int> stk;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
        freq[nums[i]]++; // 숫자 등장 횟수 표시
    }

    for(int i = n - 1; i >= 0; i--)
    {
        int cur = nums[i];

        while(!stk.empty() && freq[cur] >= freq[nums[stk.top()]])
        {
            stk.pop();
        }

        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(nums[stk.top()]);

        stk.push(i);

    }

    for(int i = n - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}