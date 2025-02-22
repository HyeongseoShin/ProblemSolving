// https://www.acmicpc.net/problem/1027
// 스스로 못 풂
// 참고: https://sookr5416.tistory.com/222

// 기울기 공식 까먹음
// 나보다 더 낮거나 or 더 높은 건물만 볼 수 있는 줄 알았음
// 기울기 : (y2 - y1) / (x2 - x1)
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

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

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        double tmp = 0;

        for(int j = i-1; j >= 0; j--)
        {
            double slope = (double)(v[i] - v[j]) / (i - j);
            if(j == i - 1 || slope < tmp)
            {
                cnt++;
                tmp = slope;
            }
        }

        tmp = 0;
        for(int j = i+1; j < n; j++)
        {
            double slope = (double)(v[j] - v[i]) / (j - i);
            if(j == i + 1 || slope > tmp)
            {
                cnt++;
                tmp = slope;
            }
        }

        ans = max(ans, cnt);

    }

    cout << ans << "\n";
    
    return 0;
}