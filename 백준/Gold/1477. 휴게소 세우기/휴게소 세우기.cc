#include <bits/stdc++.h>

using namespace std;

// 현재 휴게소 개수, 더 지으려는 휴게소 개수, 고속도로 길이
int n, m, l;

vector<int> v; // 휴게소 설치 위치

// 현재 휴게소 없는 최대 길이가 X 일때 휴게소 M개 지을 수 있는가?
int16_t GetRestCnt(int len)
{
    int rest = 0;

    for(int i = 0; i < (int)v.size() ;i++)
    {
        int dist = v[i+1] - v[i]; // 현재 두 휴게소 사이의 거리

        // 두 휴게소 사이에서 길이가 len보다 작도록 휴게소 설치하는 개수
        int cnt = dist / len;

        // 설치 가능하면
        if(cnt > 0)
        {
            if(dist % len == 0) rest += (cnt - 1);
            else rest += cnt;
        }
    }

    return rest;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l;

    v.push_back(0);
    v.push_back(l);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }
    
    
    sort(v.begin(), v.end());

    int st = 1;
    int en = l - 1;

    int ans = INT_MAX;

    while(st <= en)
    {
        int mid = (st + en) / 2;

        if(GetRestCnt(mid) <= m)
        {
            ans = min(ans, mid);
            en = mid - 1;
        }
        else st = mid + 1;
    }

    cout << ans << "\n";


    return 0;
}