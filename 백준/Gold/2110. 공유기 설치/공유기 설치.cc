#include <bits/stdc++.h>

using namespace std;

int n, c;

vector<int> home;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        home.push_back(x);
    }

    sort(home.begin(), home.end());

    int st = 0;

    // 48% 틀렸습니다 원인 : 원래 en = MAX였음
    int en = home[n - 1] - home[0];
    int ans = 0;

    while(st <= en)
    {
        // 현재 가장 가까운 거리
        int mid = (st + en) / 2;

        // 첫 번째 집은 무조건 설치
        int pos = home[0];
        int cnt = 1;
        
        for(int i = 1; i < n; i++)
        {
            if(home[i] - pos >= mid)
            {
                pos = home[i];
                cnt++;
            }
        }

        if(cnt < c) en = mid - 1;
        else
        {
            ans = mid;
            st = mid + 1;
        }
    }  

    cout << ans << "\n";

    return 0;
}