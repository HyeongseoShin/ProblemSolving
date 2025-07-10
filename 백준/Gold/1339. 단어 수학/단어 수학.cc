#include <bits/stdc++.h>

using namespace std;

int order[26]; // 각 알파벳의 번호 저장
int weights[26]; // 각 알파벳이 가지는 가중치

int n;

int ans = 0;

vector<string> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fill(order, order + 26, -1);
    for(int i = 0 ; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = (int)s.length() - 1; j >= 0; j--)
        {
            char idx = s[j] - 'A';

            weights[idx] += pow(10, (int)s.length() - 1 - j);
        }
    }

    vector<int> cnt;
    for(int i = 0; i < 26; i++)
    {
        if(weights[i] > 0)
        {
            cnt.push_back(weights[i]);
        }
    }

    sort(cnt.begin(), cnt.end(), greater<>());

    int num = 9;
    for(int i = 0; i < (int)cnt.size(); i++)
    {
        ans += (num--) * cnt[i];
    }

    cout << ans << "\n";

    return 0;
}