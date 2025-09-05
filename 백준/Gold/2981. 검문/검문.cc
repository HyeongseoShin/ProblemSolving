#include <bits/stdc++.h>

using namespace std;

int n;

int nums[101];

set<int> ans;

// 최대 공약수 구하기
int GCD(int a, int b)
{
    if(a == 0) return b;
    return GCD(b%a, a);
}

void GetAns()
{
    vector<int> gap; // 두 수의 차이의 절댓값을 담아둘 배열

    // A, B를 M으로 나눈 나머지가 같음 => (A - B) % M = 0
    for(int i = 0; i < n - 1; i++) gap.push_back(abs(nums[i+1] - nums[i]));

    int m = gap[0];

    for(int i = 1; i < (int)gap.size(); i++)
    {
        m = GCD(max(m, gap[i]), min(m, gap[i]));
    }

    ans.insert(m);
    for(int i = 2; i * i <= m; i++)
    {
        if(m % i == 0)
        {
            ans.insert(i);
            ans.insert(m / i);
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> nums[i];

    GetAns();

    for (auto x : ans) cout << x << " ";
    cout << "\n";

    GetAns();

}